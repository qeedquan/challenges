#!/usr/bin/env python3

"""

In an attempt to boost sales, the manager of the pizzeria you work at has devised a pizza rewards system: if you already made at least 5 orders of at least 20 dollars, you get a free 12 inch pizza with 3 toppings of your choice.

However, the rewards system may change in the future. Your manager wants you to implement a function that, given a dictionary of customers, a minimum number of orders and a minimum order value, returns a set of the customers who are eligible for a reward.

Customers in the dictionary are represented as:

{ 'customerName' : [list_of_order_values_as_integers] }

See example test case for more details.

"""

def rewards(customers, min_orders, min_price):
    result = []
    for name in customers:
        orders = 0
        for price in customers[name]:
            if price >= min_price:
                orders += 1
        if orders >= min_orders:
            result.append(name)
    return result

def main():
    min_orders = 5
    min_price = 20
    customers = {
        'John Doe' : [22, 30, 11, 17, 15, 52, 27, 12], # Only has four orders of 20$ or more, so no pizza
        'Jane Doe' : [5, 17, 30, 33, 40, 22, 26, 10, 11, 45] # Has six orders of 20$ or more, which means FREE PIZZA!
    }
    assert(rewards(customers, min_orders, min_price) == ['Jane Doe'])

    min_orders = 2
    min_price = 50
    customers = {
        'Joey Bonzo' : [22, 67, 53, 29], # Has two orders of 50$ or more, which means FREE PIZZA!
        'Jennifer Bonzo' : [51, 19] # Only has one order of 50$ or more, so no pizza
    }
    assert(rewards(customers, min_orders, min_price) == ['Joey Bonzo'])

    min_orders = 3
    min_price = 15
    customers = {
        'Natsumi Sakamoto' : [15, 15, 14], # Only has two orders of 15$ or more, so no pizza
        'Gorou Hironaka' : [15, 15, 15], # Has three orders of 15$ or more, which means FREE PIZZA!
        'Shinju Tanabe' : [120, 240], # Only has two orders of 15$ or more, so no pizza
    }
    assert(rewards(customers, min_orders, min_price) == ['Gorou Hironaka'])

main()
