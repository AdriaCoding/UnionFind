import pandas as pd
import matplotlib.pyplot as plt

# Parameters
n = 1000
del_val = 10

# Load data from CSV files without headers
TPL_filename = f"data/dataTPL_n{n}_del{del_val}.csv"
TPU_filename = f"data/dataTPU_n{n}_del{del_val}.csv"

TPL_data = pd.read_csv(TPL_filename, header=None)
TPU_data = pd.read_csv(TPU_filename, header=None)

# Plot stacked TPL data
plt.figure(figsize=(10, 6))
for row in TPL_data.iterrows():
    method = row[1][0]  # First column contains the method name
    TPL_values = row[1][1:]  # Remaining columns contain the data
    adjusted_TPL_values = [val / n for val in TPL_values]  # Adjust by dividing by n
    plt.plot(range(0, len(adjusted_TPL_values) * del_val, del_val), adjusted_TPL_values, label=f"{method}")
plt.ylabel("Unions performed")
plt.ylabel("TPU / n")
plt.title("Total Path Length (Adjusted)")
plt.legend()
plt.grid(True)
plt.show()

# Plot TPU data
plt.figure(figsize=(10, 6))
for row in TPU_data.iterrows():
    method = row[1][0]  # First column contains the method name
    if not method.endswith("_NC"):  # Check if method name doesn't end with "_NC"
        TPU_values = row[1][1:]  # Remaining columns contain the data
        adjusted_TPU_values = [val / n for val in TPU_values]  # Adjust by dividing by n
        plt.plot(range(0, len(adjusted_TPU_values) * del_val, del_val), adjusted_TPU_values, label=f"{method}")
plt.xlabel("Unions performed")
plt.ylabel("TPL / n")
plt.title("Total Pointer Updates (Adjusted)")
plt.legend()
plt.grid(True)
plt.show()
