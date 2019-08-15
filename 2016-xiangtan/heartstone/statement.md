# Heartstone

Bobo is playing *Heartstone*.
There are $n$ minions in the battlefield.
The $i$-th minion has $h_i$ hit points (HP).

Bobo uses two kinds of magic.
The one is *Arcane Shot* and the other is *Frostbolt*.
*Arcane Shot* can deal **two** points damage to a minion
(that is to decrease the minion's HP by two),
while *Frostbolt* can deal **three** points damage.
A minion is killed when its HP is less or equal to zero.

Let $f(a)$ be the minimum number of *Frostbolt*(s) required to kill all minions,
if no more than $a$ *Arcane Shot*(s) are used.
Bobo would like to find out $f(0) + f(1) + \dots + f(m)$ modulo $(10^9+7)$.

## Input

The input contains at most $30$ sets. For each set:

The first line contains $2$ integers $n ,m$ ($1 \leq n \leq 10^5, 0 \leq m \leq 10^5$).

The second line contains $n$ integers $h_1, h_2, \dots, h_n$ ($1 \leq h_i \leq 10^4$).

## Output

For each set, an integer denotes $f(0) + f(1) + \dots + f(m)$ modulo $(10^9+7)$.

<!--SAMPLES-->
