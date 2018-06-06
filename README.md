# Algo-Trading
#### Algorithmic trading models and expert advisors (trading bots)
-----------------------
### TimeCheck
Since many brokers will charge extra commission on trades held overnight/after market close, it can be useful to have a built-in safety that will both cease making trades when the time is out of market hours, but will also close any rogue trades that are still open.

The main idea of this program is the bool AllowTrade, as it can be placed at the beginning of any trading bot and will ensure it only works during the times given. 

If you do want to turn it off, and allow trades overnight/after hours, then simply change
```C
extern bool UseTimeLimit = true;
```
to ```false```. The ```extern``` before any variable allows you to edit it in MT4 itself, and there is no need to edit the code.

