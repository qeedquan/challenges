<#

Given integers a and b. Calculate the value a^b mod p, where p=1000000007.

Examples
Input #1
5
3

Answer #1
125

#>

function Invoke-ModularExponentiation {
    param (
        [Parameter(Mandatory=$true)]
        [bigint]$Base,

        [Parameter(Mandatory=$true)]
        [bigint]$Exponent
    )

    $modulus = 1000000007
    $result = [bigint]::One
    $base = $Base % $modulus

    while ($Exponent -gt 0) {
        if (($Exponent % 2) -eq 1) {
            $result = ($result * $base) % $modulus
        }
        $Exponent = [bigint]::Divide($Exponent, 2)
        $base = ($base * $base) % $modulus
    }
    return $result
}

$result = Invoke-ModularExponentiation -Base 5 -Exponent 3
Write-Host "$result"
