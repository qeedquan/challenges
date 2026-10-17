#!/usr/bin/env pwsh

<#

Description:
So went to a Casino recently. I noticed at the Blackjack tables the house tends to use several decks and not 1. My mind began to wonder about how likely natural blackjacks (getting an ace and a card worth 10 points on the deal) can occur.

So for this monday challenge lets look into this. We need to be able to shuffle deck of playing cards. (52 cards) and be able to deal out virtual 2 card hands and see if it totals 21 or not.

Develop a way to shuffle 1 to 10 decks of 52 playing cards.

Using this shuffle deck(s) deal out hands of 2s

count how many hands you deal out and how many total 21 and output the percentage.

Input:
n: being 1 to 10 which represents how many deck of playing cards to shuffle together.

Output:
After x hands there was y blackjacks at z%.

Example Output:
After 26 hands there was 2 blackjacks at %7.

Optional Output:
Show the hands of 2 cards. So the card must have suit and the card.

D for diamonds, C for clubs, H for hearts, S for spades or use unicode characters.

Card from Ace, 2, 3, 4, 5, 6, 8, 9, 10, J for jack, Q for Queen, K for king

Make Challenge Easier:
Just shuffle 1 deck of 52 cards and output how many natural 21s (blackjack) hands if any you get when dealing 2 card hands.

Make Challenge Harder:
When people hit in blackjack it can effect the game. If your 2 card hand is 11 or less always get a hit on it. See if this improves or decays your rate of blackjacks with cards being used for hits.

Card Values:
Face value should match up. 2 for 2, 3 for 3, etc. Jacks, Queens and Kings are 10. Aces are 11 unless you get 2 Aces then 1 will have to count as 1.

Source:
Wikipedia article on blackjack/21 [Link to article on wikipedia] (http://en.wikipedia.org/wiki/Blackjack)

#>

# ported from @KillerCodeMonky solution
function Random-Hands([int] $decks, [int] $count) {
    $blackjacks = 0;
    for($i = 0; $i -lt $count; ++$i) {
        $hand = Random-Hand $decks;
        Write-Host $($hand.Cards |% { Get-CardName $_ }) -> $hand.Value;
        if ($hand.Value -eq 21) {
            $blackjacks += 1;
        }
    }
    
    Write-Host "Had $blackjacks blackjacks in $count hands ($($blackjacks / $count * 100)%).";
}

function Random-Hand([int] $decks) {
    # Pick two unique cards.
    $cards = @();
    while ($cards.Length -lt 2) {
        $cards += Get-RandomCard $decks $($cards |% { $_.Raw });
    }
    
    # Sum all the cards.
    $sum = Sum-Cards $cards;
    
    # Hit as long as 11 or fewer points.
    while($sum -le 11) {
        $cards += Get-RandomCard $decks $($cards |% { $_.Raw });
        $sum = Sum-Cards $cards;
    }
    
    return New-Object -TypeName PSObject -Prop @{
        "Cards" = $cards;
        "Value" = $sum;
    };
}

function Get-RandomCard([int] $decks, [int[]] $alreadyPicked) {
    $card = Get-Random -Minimum 0 -Maximum (52 * $decks - 1);
    while($alreadyPicked -contains $card) {
        $card = Get-Random -Minimum 0 -Maximum (52 * $decks - 1);
    }
    
    return New-Object -TypeName PSObject -Prop @{
        "Raw" = $card;
        "Rank" = [Math]::Floor(($card % 52) / 4) + 1;
        "Suit" = $card % 4;
    };
}

function Sum-Cards($cards) {
    $ranks = $cards |% { $_.Rank };
    $sum = 0;
    $aces = 0;
    foreach($rank in $ranks) {
        if ($rank -eq 1 -and $sum -lt 11) {
            # Ace.
            $sum += 11;
            $aces += 1;
        } elseif ($rank -gt 10) {
            # Face.
            $sum += 10;
        } else {
            # Number.
            $sum += $rank;
        }
    }
    
    # Demote aces.
    while($sum -gt 21 -and $aces -gt 0) {
        $sum -= 10;
        $aces -= 1;
    }
    
    return $sum;
}

function Get-CardName($card) {
    if ($card.Suit -eq 0) {
        $suit = "♠";
    } elseif ($card.Suit -eq 1) {
        $suit = "♥";
    } elseif ($card.Suit -eq 2) {
        $suit = "♦";
    } else {
        $suit = "♣";
    }
    
    if ($card.Rank -eq 1) {
        return "A" + $suit;
    } elseif ($card.Rank -eq 11) {
        return "J" + $suit;
    } elseif ($card.Rank -eq 12) {
        return "Q" + $suit;
    } elseif ($card.Rank -eq 13) {
        return "K" + $suit;
    } else {
        return $card.Rank.ToString() + $suit;
    }
}

Random-Hands 5 20
echo ""
Random-Hands 6 40
