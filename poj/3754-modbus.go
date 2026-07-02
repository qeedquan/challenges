/*

Description

在嵌入式系统开发中，Modbus协议是工业控制系统中广泛应用的一种协议。本题用来简单模拟Modbus协议，只需根据条件生成符合该协议的数据帧，并解析所获取的数据。
假设设备使用的协议发送数据格式如下：
<SlaveAddress, 1 Byte> <Function, 1 Byte> <Start Address, 2 Bytes> <NumberofBytes, 2 Bytes> <Checksum, 2 Bytes>
其中前四项将在输入条件中给出，最后一项为CRC校验和，需根据前四项的数据，按照CRC算法进行计算。注意数据的长度，多于1byte的高位在前，低位在后。该CRC校验算法的描述如下：
1)将CRC赋值0xFFFF。
2)取初始信息的第一个字节（8位）与CRC进行异或运算，将结果赋给CRC。
3)将CRC数据右移一位，最前位（左边）补0。
4)如果右移前，CRC最低位（最右端）为1，则将右移后的CRC与0xA001进行异或运算，且将结果赋给CRC。否则，跳过此步。
5)重复3，4步8次（即右边8位）。
6)对初始信息的下一个字节，同样执行2，3，4，5步，直到信息中所有字节都执行了同样的步骤。
7)将此时得到的CRC值的高8位和低8位交换，即得到CRC校验和。

对应的接收格式如下：
<SlaveAddress,1Byte> <Function,1Byte> <NumberofBytes,1Byte> <DataIEEE32,xByte> <Checksum,2Bytes>
其中DataIEEE32为一个或多个按IEEE754标准定义的32位浮点数，具体的数据长度由NumberofBytes项来决定(比如NumberofBytes为4，则DataIEEE32项为4 bytes，正好表示一个浮点数；如为8，则DataIEEE32项为8 bytes，可表示两个浮点数)。本题要求编程实现从IEEE32数据（如“420B999A”）到浮点数（如34.9）的转换，从而解析出浮点数值。

提示：你可以根据IEEE754标准自行设计转换算法；或者直接利用C语言float类型的实现特性：x86 linux下，gcc编译器将C语言代码“float f = 34.9;”编译成汇编代码“movl $0x420b999a, -4(%ebp)” （AT&T x86汇编格式），也就是说，单精度浮点数34.9在内存中就是由整数0x420b999a来表示的，你可以利用这一特性来完成转换。

Input

输入包含多组数据，以EOF结束
每组数据共两行。
第一行共四个十进制整数，分别为协议格式要求的：<SlaveAddress, 1 Byte>,<Function, 1 Byte>,<Start Address, 2 Bytes>,<NumberofBytes, 2 Bytes>，以逗号“,”分开。
如：1,4,40,2
其中：1为SlaveAddress；4为Function；40为Start Address；2为NumberofBytes。
第二行为符合接收格式的数据帧（16进制表示），需从其中解析所接收的数据，其长度小于64个字符，浮点数数据最多为4个（即DataIEEE32数据项最多为32bytes）。
如: 010404420B999A7405
其中：01为SlaveAddress；04为Function；04为NumberofBytes； 420B999A 为DataIEEE32；7405为Checksum。

Output

每组数据输出共两行。
第一行：根据输入结果的第一行，输出完整的符合该协议发送格式的数据帧，数据用16进制大写表示，每部分的长度都要求符合协议格式，比如Start Address项如果不到2 bytes，则需要在左边补零。
如：010400280002F1C3
其中：01为SlaveAddress；04 为Function；0028为Start Address；0002为NumberofBytes；F1C3为Checksum。

第二行：根据输入结果的第二行，依次解析IEEE32数据，将其转换成浮点数并打印结果（小数点后保留一位）。解析之前需检查CRC校验和，如校验失败则直接打印CRC_ERROR。如有多个数据，用逗号分隔。
如：34.9
该浮点值为420B999A所对应的值。

Sample Input

1,4,40,2
010404420B999A7405
1,4,40,2
010404420B999A7404
2,4,383,4
02040841CC0000477F2100DF85


Sample Output

010400280002F1C3
34.9
010400280002F1C3
CRC_ERROR
0204017F0004C1DE
25.5,65313.0

Source

*/

package main

import (
	"encoding/binary"
	"fmt"
	"math"
)

func main() {
	fmt.Println(encode(1, 4, 40, []byte{0x42, 0x0b, 0x99, 0x9a}))
	fmt.Println(encode(2, 4, 383, []byte{0x41, 0xCC, 0x00, 0x00, 0x47, 0x7F, 0x21, 0x00}))
}

func encode(slave, function uint8, addr uint16, data []byte) (hdr string, vals []float32, err error) {
	datalen := len(data)
	if datalen/2 > math.MaxUint16 || datalen%4 != 0 {
		err = fmt.Errorf("invalid data size")
		return
	}

	buf := make([]byte, 8)
	buf[0] = slave
	buf[1] = function
	binary.BigEndian.PutUint16(buf[2:], addr)
	binary.BigEndian.PutUint16(buf[4:], uint16(datalen/2))
	binary.BigEndian.PutUint16(buf[6:], crc16(buf[:len(buf)-2]))
	for i := 0; i < datalen; i += 4 {
		bits := binary.BigEndian.Uint32(data[i:])
		vals = append(vals, math.Float32frombits(bits))
	}
	hdr = fmt.Sprintf("%02X", buf)
	return
}

func crc16(buf []byte) uint16 {
	crc := uint16(0xFFFF)
	for _, val := range buf {
		crc ^= uint16(val)
		for i := 8; i > 0; i-- {
			if (crc & 0x0001) != 0 {
				crc >>= 1
				crc ^= 0xA001
			} else {
				crc >>= 1
			}
		}
	}
	return crc>>8 | crc<<8
}
