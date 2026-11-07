#!/usr/bin/env python3

"""

On the Forex Market the currency symbols for exchange between two currencies are put together in regards to their strength and weakness. The order of the currency strength is as follows:

"EUR", "GBP", "AUD", "NZD", "USD", "CAD", "CHF", "JPY"

So for AUD the currency matrix would be as follows EURAUD, GBPAUD, AUDNZD, AUDUSD, AUDCAD, AUDCHF, AUDJPY

Your goal is to generate this currency matrix for a given currency. You can assume that the passed in currency is a valid one.

"""

def matrix(currency):
    currencies = ["EUR", "GBP", "AUD", "NZD", "USD", "CAD", "CHF", "JPY"]
    
    position = currencies.index(currency)
    if position < 0:
        return []

    result = []
    for index in range(len(currencies)):
        if index < position:
            result.append(currencies[index] + currency)
        elif index > position:
            result.append(currency + currencies[index])
    return result

def main():
    assert(matrix("AUD") == ["EURAUD", "GBPAUD", "AUDNZD", "AUDUSD", "AUDCAD", "AUDCHF", "AUDJPY"])

main()
