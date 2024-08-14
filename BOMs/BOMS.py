import pandas as pd

# Read the CSV files into DataFrames
df1 = pd.read_csv('bom_Main_PCB.csv')
df2 = pd.read_csv('bom_Solar_Module.csv')

# Add a new column to indicate the source
df1['Source'] = 'Main_PCB'
df2['Source'] = 'Solar_Module'

# Concatenate the DataFrames
df = pd.concat([df1, df2])

# Group by 'Value' and 'Footprint', then sum the 'Quantity' and join the 'Designator'
df_grouped = df.groupby(['Value', 'Footprint'], as_index=False).agg({'Quantity': 'sum', 'Designator': ','.join})

# Sort the DataFrame by 'Designator' alphabetically
df_grouped = df_grouped.sort_values(by='Designator')

# Drop the 'LCSC Part #' column
df_grouped = df_grouped.drop(columns=['LCSC Part #'], errors='ignore')

# Save the result to a new CSV file
df_grouped.to_csv('Merged_BOM.csv', index=False)

print("The data has been processed, sorted, and saved.")