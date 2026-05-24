import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import string
import numpy as np

sns.set_theme(style="ticks", context="paper")
plt.rcParams["font.family"] = "Arial"

no_astro = pd.read_csv(
    "high_freq_2.dat",
    delim_whitespace=True
)

astro_low = pd.read_csv(
    "astro_1.dat",
    delim_whitespace=True
)

astro_high = pd.read_csv(
    "astro_2.dat",
    delim_whitespace=True
)





letters = string.ascii_lowercase

# color granate
color = "#8c2d2d"
plt.close('all')
# coger run 0
no_astro = no_astro[no_astro["run"] == 0]

astro_low = astro_low[astro_low["run"] == 0]

astro_high = astro_high[astro_high["run"] == 0]



# figura
fig, axes = plt.subplots(
    3, 2,
    figsize=(12,6),
    sharex=True
)

axes[0,1].plot(
    no_astro["t"],
    no_astro["cai"],
    color="#3465a4",
    linewidth=1.0
)

axes[0,1].set_ylabel("Ca$i$ (mM)", fontsize=12)


axes[0,0].plot(
    no_astro["t"],
    no_astro["v"],
    color="#8c2d2d",
    linewidth=1.0
)

axes[0,0].set_ylabel("mV", fontsize=12)

axes[0,0].legend(
    ["No astro. Frequency = 4,59 Hz"],
    frameon=True,
    fontsize=11,
    loc="upper right",
    facecolor="white",
    edgecolor="none",
    framealpha=0.9
)

axes[1,1].plot(
    astro_low["t"],
    astro_low["cai"],
    color="#3465a4",
    linewidth=1.0
)

axes[1,1].set_ylabel("Ca$i$ (mM)", fontsize=12)
axes[1,1].set_xlabel("Tiempo (ms)", fontsize=12)


axes[1,0].plot(
    astro_low["t"],
    astro_low["v"],
    color="#8c2d2d",
    linewidth=1.0
)

axes[1,0].set_ylabel("mV", fontsize=12)


axes[1,0].legend(
    ["Astro (2000 ms, 0,1 factor). Frequency = 4,49 Hz"],
    frameon=True,
    fontsize=11,
    loc="upper right",
    facecolor="white",
    edgecolor="none",
    framealpha=0.9
)

axes[2,1].plot(
    astro_high["t"],
    astro_high["cai"],
    color="#3465a4",
    linewidth=1.0
)

axes[2,1].set_ylabel("Ca$i$ (mM)", fontsize=12)
axes[2,1].set_xlabel("Tiempo (ms)", fontsize=12)


axes[2,0].plot(
    astro_high["t"],
    astro_high["v"],
    color="#8c2d2d",
    linewidth=1.0
)

axes[2,0].set_ylabel("mV", fontsize=12)


axes[2,0].legend(
    ["Astro (2000 ms, 0,2 factor). Frequency = 4,42 Hz"],
    frameon=True,
    fontsize=11,
    loc="upper right",
    facecolor="white",
    edgecolor="none",
    framealpha=0.9
)


axes[2,0].set_xlabel("Tiempo (ms)", fontsize=12)

for ax in axes.flatten():

    ax.set_xlim(0, 3000)

    ax.tick_params(
        direction='out',
        length=5,
        width=1
    )

    sns.despine(ax=ax)

for i, ax in enumerate(axes.flatten()):

    ax.text(
        -0.12,
        0.92,
        f"{letters[i]})",
        transform=ax.transAxes,
        fontsize=12,
        fontweight="bold"
    )


# quitar caja
sns.despine()



t = astro_low["t"].values

# frecuencia -> periodo 2000 ms
period = 2000

# senoide base
astro_wave = np.sin(2 * np.pi * t / period)

# dejar solo parte positiva
astro_wave[astro_wave < 0] = 0

# escalar al rango del calcio
astro_wave_low = astro_wave * 0.0005
astro_wave_high = astro_wave * 0.001

axes[1,1].plot(
    t,
    astro_wave_low,
    color="#2e8b57",
    linewidth=2,
    linestyle="--",
    alpha=0.7,
    label="Astrocytic modulation"
)

axes[1,1].legend(
    frameon=True,
    fontsize=10,
    loc="upper right"
)


axes[2,1].plot(
    t,
    astro_wave_high,
    color="#2e8b57",
    linewidth=2,
    linestyle="--",
    alpha=0.7,
    label="Astrocytic modulation"
)

axes[2,1].legend(
    frameon=True,
    fontsize=10,
    loc="upper right"
)
plt.tight_layout()

plt.savefig(
    "figs/astro_comparison_final.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()