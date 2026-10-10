#!/usr/bin/env pwsh

<#

Description

编写一个C程序实现将字符串中的所有"you"替换成"we"

Input

输入包含多行数据

每行数据是一个字符串，长度不超过1000
数据以EOF结束

Output

对于输入的每一行，输出替换后的字符串

Sample Input

you are what you do

Sample Output

we are what we do

Source

#>

function youwe($str) {
	$str.replace("you", "we")
}

youwe "you are what you do"
