import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import string

sns.set_theme(style="ticks", context="paper")
plt.rcParams["font.family"] = "Arial"

low_df = pd.read_csv(
    "low_freq.dat",
    delim_whitespace=True
)

high_df = pd.read_csv(
    "high_freq.dat",
    delim_whitespace=True
)

high_df2 = pd.read_csv(
    "high_freq_2.dat",
    delim_whitespace=True
)

letters = string.ascii_lowercase

# color granate
color = "#8c2d2d"
plt.close('all')
# coger run 0
run_lowfreq = low_df[low_df["run"] == 0]

run_highfreq = high_df[high_df["run"] == 0]

run_highfreq2 = high_df2[high_df2["run"] == 0]

# figura
fig, axes = plt.subplots(
    3, 1,
    figsize=(11,6),
    sharex=True
)

axes[0].plot(
    run_lowfreq["t"],
    run_lowfreq["v"],
    color="#8c2d2d",
    linewidth=1.0
)

axes[0].set_ylabel("mV", fontsize=12)

axes[0].set_ylim(-80, 40)

axes[0].legend(
    ["Low frequency = 0,81 Hz"],
    frameon=True,
    fontsize=11,
    loc="upper right",
    facecolor="white",
    edgecolor="none",
    framealpha=0.9
)

axes[1].plot(
    run_highfreq["t"],
    run_highfreq["v"],
    color="#8c2d2d",
    linewidth=1.0
)

axes[1].set_ylabel("mV", fontsize=12)



axes[1].set_ylim(-80, 40)

axes[1].legend(
    ["Medium frequency = 2,43 Hz"],
    frameon=True,
    fontsize=11,
    loc="upper right",
    facecolor="white",
    edgecolor="none",
    framealpha=0.9
)

axes[2].plot(
    run_highfreq2["t"],
    run_highfreq2["v"],
    color="#8c2d2d",
    linewidth=1.0
)

axes[2].set_ylabel("mV", fontsize=12)

axes[2].set_ylim(-80, 40)

axes[2].legend(
    ["High frequency = 4,59 Hz"],
    frameon=True,
    fontsize=11,
    loc="upper right",
    facecolor="white",
    edgecolor="none",
    framealpha=0.9
)

axes[2].set_xlabel("Tiempo (ms)", fontsize=12)
for ax in axes:

    ax.set_xlim(0, 3000)

    ax.tick_params(
        direction='out',
        length=5,
        width=1
    )

    sns.despine(ax=ax)

for i, ax in enumerate(axes):

    ax.text(
        -0.08,
        0.9,
        f"{letters[i]})",
        transform=ax.transAxes,
        fontsize=12,
        fontweight="bold"
    )


# ticks
plt.tick_params(
    direction='out',
    length=5,
    width=1
)

# quitar caja
sns.despine()



plt.tight_layout()

plt.savefig(
    "figs/freq_comparison.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()