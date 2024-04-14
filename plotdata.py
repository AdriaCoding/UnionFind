import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

# Parameters
n = 5000
del_val = 50
epsilon = 2

# Load data from CSV files without headers
TPL_filename = f"data/dataTPL_n{n}_del{del_val}.csv"
TPU_filename = f"data/dataTPU_n{n}_del{del_val}.csv"

TPL_data = pd.read_csv(TPL_filename, header=None)
TPU_data = pd.read_csv(TPU_filename, header=None)

# Define cost functions
def calculate_cost_NC(TPL):
    return TPL

def calculate_cost_FC(TPL, TPU):
    return 2 * TPL + epsilon * TPU

def calculate_cost_PS_PH(TPL, TPU):
    return TPL + epsilon * TPU

# Plotting
plt.set_cmap('tab10')
fig, ax = plt.subplots(figsize=(10, 6))
# Loop over the data and calculate costs for different methods
for row_tpl, row_tpu in zip(TPL_data.iterrows(), TPU_data.iterrows()):
    method_name = row_tpl[1][0]
    #if method_name.startswith('QU_'):
    #    continue
    
    tpl_values = row_tpl[1][1:]
    tpu_values = row_tpu[1][1:]
    
    # Calculate costs based on method name
    if method_name.endswith("_NC"):
        costs = [calculate_cost_NC(tpl) for tpl in tpl_values]
    elif method_name.endswith("_FC"):
        costs = [calculate_cost_FC(tpl, tpu) for tpl, tpu in zip(tpl_values, tpu_values)]
    elif method_name.endswith("_PS") or method_name.endswith("_PH"):
        costs = [calculate_cost_PS_PH(tpl, tpu) for tpl, tpu in zip(tpl_values, tpu_values)]
    
    # Plot the costs
    ax.plot(range(0, len(costs) * del_val, del_val), costs, label=method_name)

ax.set_xlabel("Unions performed")
ax.set_ylabel("Cost")
ax.set_title(f"Cost comparison with epsilon={epsilon}")
#ax.set_ylim(0, 15000)
ax.legend()
ax.grid(True)

plt.tight_layout()
plt.savefig(f"Cost comparison eps={epsilon} n={n}")
