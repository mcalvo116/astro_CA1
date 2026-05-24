import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import string

sns.set_theme(style="ticks", context="paper")
plt.rcParams["font.family"] = "Arial"
plt.close('all')
df = pd.read_csv(
    "all_runs_astro.dat",
    delim_whitespace=True
)

# crear figura
fig, axes = plt.subplots(
    10, 1,
    figsize=(10, 14),
    sharex=True
)

letters = string.ascii_lowercase

# color granate
color = "#8c2d2d"

for run in range(10):

    ax = axes[run]

    sub = df[df["run"] == run]

    ax.plot(
        sub["t"],
        sub["v"],
        color=color,
        linewidth=1.2
    )

    # límites típicos neurona
    ax.set_ylim(-80, 40)

    # quitar caja
    sns.despine(ax=ax)

    # ticks
    ax.tick_params(
        direction='out',
        length=4,
        width=1
    )

    # etiqueta a), b), c)...
    ax.text(
        -0.08, 0.85,
        f"{letters[run]})",
        transform=ax.transAxes,
        fontsize=12,
        fontweight="bold"
    )

    stim_amp = 0.71 + run * 0.02

    ax.text(
        0.02, 0.85,
        f"{stim_amp:.2f} nA",
        transform=ax.transAxes,
        fontsize=10
    )

# labels globales
fig.supxlabel("Tiempo (ms)", fontsize=14)
fig.supylabel(
    "Potencial de membrana (mV)",
    fontsize=14,
    x=0.01
)


plt.tight_layout()

plt.savefig(
    "figs/all_runs.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()