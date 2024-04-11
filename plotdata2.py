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

# Filter data for different methods
QU_TPL_data = TPL_data[TPL_data[0].str.startswith("QU_")]
UR_TPL_data = TPL_data[TPL_data[0].str.startswith("UR_")]
UW_TPL_data = TPL_data[TPL_data[0].str.startswith("UW_")]

QU_TPU_data = TPU_data[TPU_data[0].str.startswith("QU_")]
UR_TPU_data = TPU_data[TPU_data[0].str.startswith("UR_")]
UW_TPU_data = TPU_data[TPU_data[0].str.startswith("UW_")]

# Create a single figure with two subplots
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8))

# Plot TPL data for QU_ methods
for row in QU_TPL_data.iterrows():
    method_name = row[1][0]
    values = row[1][1:]
    adjusted_values = [val / n for val in values]
    ax1.plot(range(0, len(adjusted_values) * del_val, del_val), adjusted_values, label=f"{method_name}")

ax1.set_xlabel("Unions performed")
ax1.set_ylabel("TPL / n")
ax1.legend()
ax1.grid(True)

# Plot TPU data for QU_ methods
for row in QU_TPU_data.iterrows():
    method_name = row[1][0]
    values = row[1][1:]
    adjusted_values = [val / n for val in values]
    ax2.plot(range(0, len(adjusted_values) * del_val, del_val), adjusted_values, label=f"{method_name}")

ax2.set_xlabel("Unions performed")
ax2.set_ylabel("TPU / n")
ax2.legend()
ax2.grid(True)

fig.suptitle("Quick Union", fontsize=16)

plt.tight_layout()
plt.show()

# Create a single figure with two subplots for UR_ methods
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8))

# Plot TPL data for UR_ methods
for row in UR_TPL_data.iterrows():
    method_name = row[1][0]
    values = row[1][1:]
    adjusted_values = [val / n for val in values]
    ax1.plot(range(0, len(adjusted_values) * del_val, del_val), adjusted_values, label=f"{method_name}")

ax1.set_xlabel("Unions performed")
ax1.set_ylabel("TPL / n")
ax1.legend()
ax1.grid(True)

# Plot TPU data for UR_ methods
for row in UR_TPU_data.iterrows():
    method_name = row[1][0]
    values = row[1][1:]
    adjusted_values = [val / n for val in values]
    ax2.plot(range(0, len(adjusted_values) * del_val, del_val), adjusted_values, label=f"{method_name}")

ax2.set_xlabel("Unions performed")
ax2.set_ylabel("TPU / n")
ax2.legend()
ax2.grid(True)

fig.suptitle("Union by Rank", fontsize=16)

plt.tight_layout()
plt.show()


# Create a single figure with two subplots for UW_ methods
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8))

# Plot TPL data for UW_ methods
for row in UW_TPL_data.iterrows():
    method_name = row[1][0]
    values = row[1][1:]
    adjusted_values = [val / n for val in values]
    ax1.plot(range(0, len(adjusted_values) * del_val, del_val), adjusted_values, label=f"{method_name}")

ax1.set_xlabel("Unions performed")
ax1.set_ylabel("TPL / n")
ax1.legend()
ax1.grid(True)

# Plot TPU data for UW_ methods
for row in UW_TPU_data.iterrows():
    method_name = row[1][0]
    values = row[1][1:]
    adjusted_values = [val / n for val in values]
    ax2.plot(range(0, len(adjusted_values) * del_val, del_val), adjusted_values, label=f"{method_name}")

ax2.set_xlabel("Unions performed")
ax2.set_ylabel("TPU / n")
ax2.legend()
ax2.grid(True)

fig.suptitle("Union by Weight", fontsize=16)

plt.tight_layout()
plt.show()
