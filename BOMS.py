import pandas as pd
import os

# List .csv
all_files = os.listdir(os.getcwd())    
csv_files = list(filter(lambda f: f.endswith('.csv') and f != 'Merged_csv.csv', all_files))

# Merge
df = pd.concat(map(pd.read_csv, csv_files), ignore_index=True) 

# Reorder Headers
column_names = list(df.columns.values)
column_names.pop(4) # Remove LCSC Header
df = df.reindex(columns=['Value', 'Footprint', 'Quantity', 'Designator'])

df = df.groupby(['Value', 'Footprint']).agg({
    'Quantity': 'sum',
    'Designator': lambda x: ','.join(x)
}).reset_index()

df = df.sort_values('Designator')

# print(df)


# Store in new .csv
df.to_csv("Merged_csv.csv", index=False)
print("CSV is combined")