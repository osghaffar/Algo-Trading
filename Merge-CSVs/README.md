## Merge CSV's
This takes two 5 minute data charts with ranging dates and times and combines them into one. Since intermarket data is often used
to study markets and to make trading decisions, it can be useful to have two different charts inside one CSV.

However, there are often discrepancies in the time frame. For example, USDCHF may simply be missing certain bars of data,
and this can cause problems for side-by-side comparison.

This script attempts to make that problem as painless as possible by merging them. Uses pandas to handle the dataframes
with ease.
