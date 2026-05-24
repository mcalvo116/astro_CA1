import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import string

sns.set_theme(style="ticks", context="paper")
plt.rcParams["font.family"] = "Arial"

df = pd.read_csv(
    "all_runs_astro.dat",
    delim_whitespace=True
)

letters = string.ascii_lowercase

# color granate
color = "#8c2d2d"
plt.close('all')
selected_runs = [0, 4, 7]

fig, axes = plt.subplots(
    len(selected_runs),
    1,
    figsize=(10,6),
    sharex=True
)

for idx, run in enumerate(selected_runs):

    ax = axes[idx]

    sub = df[df["run"] == run]

    ax.plot(
        sub["t"],
        sub["v"],
        color="#8c2d2d",
        linewidth=1.3
    )

    ax.set_ylim(-80, 40)

    sns.despine(ax=ax)

    ax.tick_params(
        direction='out',
        length=4
    )

    ax.text(
        -0.08, 0.85,
        f"{chr(97+idx)})",
        transform=ax.transAxes,
        fontsize=12,
        fontweight="bold"
    )

    stim_amp = 0.71 + run * 0.02

    ax.text(
        0.02, 0.85,
        f"Run {run}",
        transform=ax.transAxes,
        fontsize=10
    )


    ax.text(
        0.02, 0.75,
        f"{stim_amp:.2f} nA",
        transform=ax.transAxes,
        fontsize=10
    )

    if idx != len(selected_runs)-1:
        ax.set_xticklabels([])


    
"""     # etiqueta a), b), c)...
    ax.text(
        -0.08, 0.85,
        f"{letters[run]})",
        transform=ax.transAxes,
        fontsize=12,
        fontweight="bold"
    ) """

    

# labels globales
fig.supxlabel("Tiempo (ms)", fontsize=14)
fig.supylabel(
    "Potencial de membrana (mV)",
    fontsize=14,
    x=0.01
)


plt.tight_layout()

plt.savefig(
    "figs/selected_runs.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()