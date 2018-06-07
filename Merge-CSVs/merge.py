import pandas as pd

a = pd.read_csv("/Users/Documents/Merge-CSVs/EURUSD5.csv")
b = pd.read_csv("/Users/Documents/Merge-CSVs/USDCHF5.csv")

#Merge date + time columns into one - easier for pandas to parse datetime later on
a["Datetime"] = a["Date"] + " " + a["Time"]
b["Datetime"] = b["Date"] + " " + a["Time"]

#Drop these columns as they aren't needed anymore
a = a.drop(["Date"], axis = 1)
a = a.drop(["Time"], axis = 1)

b = b.drop(["Date"], axis = 1)
b = b.drop(["Time"], axis = 1)

#Place 'datetime' at the beginning
dt = a['Datetime']
a.drop(labels=['Datetime'], axis = 1, inplace = True)
a.insert(0, 'Datetime', dt)

dt = b['Datetime']
b.drop(labels=['Datetime'], axis = 1, inplace = True)
b.insert(0, 'Datetime', dt)

#print(a.head(50))
#print(b.head(50))

#Merge the CSVs on the column 'datetime'
df = a.merge(b, on='Datetime', how='right')

#Drop any rows that don't match up
df = df.dropna(0)

#check to see if NaN values are gone
print(df.tail(300))

filename = 'CSVsjoined.csv'
df = df.to_csv(filename, sep=',')
print("File saved as", filename)
