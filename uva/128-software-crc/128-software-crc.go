package main

func main() {
	assert(crc([]byte("this is a test")) == 0x77fd)
	assert(crc([]byte("")) == 0x0000)
	assert(crc([]byte("A")) == 0x0c86)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func crc(b []byte) int {
	const mod = 34943

	v := 0
	for i := range b {
		v = (v<<8 + int(b[i])) % mod
	}
	v = mod - (v<<8)%mod
	v = (v << 8) % mod
	v = (v + mod) % mod
	return v
}
