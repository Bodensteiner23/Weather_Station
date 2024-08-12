import pandas as pd
import os
import glob

# Get the directory of the current Python file
current_dir = os.path.dirname(os.path.abspath(__file__))

# List all CSV files in the directory
csv_files = glob.glob(os.path.join(current_dir, '*.csv'))

# Process each CSV file individually
for csv_file in csv_files:
    # Read the CSV file into a DataFrame
    df = pd.read_csv(csv_file)
    
    # Group by 'Value' and 'Footprint', then sum the 'Quantity' and join the 'Designator'
    df_grouped = df.groupby(['Value', 'Footprint'], as_index=False).agg({'Quantity': 'sum', 'Designator': ','.join})
    
    # Sort the DataFrame alphabetically by 'Designator'
    df_grouped = df_grouped.sort_values(by='Designator')
    
    # Drop the 'LCSC Part #' column if it exists
    df_grouped = df_grouped.drop(columns=['LCSC Part #'], errors='ignore')
    
    # Save the result to the same CSV file
    df_grouped.to_csv(csv_file, index=False)

print("The data has been processed, sorted, and saved.")