import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
plt.close("all")
# estilo
sns.set_theme(style="ticks", context="paper")

plt.rcParams["font.family"] = "Arial"

def find_return_to_rest(df, threshold=-70.5, min_time = 200):

    v = df["v"].values
    t = df["t"].values

    # cruce ASCENDENTE desde hiperpolarización
    crossings = np.where(
        (v[:-1] < threshold) &
        (v[1:] >= threshold) &
        (t[:-1] >= min_time)
    )[0]

    if len(crossings) == 0:
        return None, None

    idx = crossings[0]

    return t[idx], v[idx]

# cargar datos
df_sahp = pd.read_csv(
    "single_run_withsahp.dat",
    delim_whitespace=True
)

df_nosahp = pd.read_csv(
    "single_run_nosahp.dat",
    delim_whitespace=True
)

# coger run 0
run_sahp = df_sahp[df_sahp["run"] == 0]

run_nosahp = df_nosahp[df_nosahp["run"] == 0]

t_sahp, v_sahp = find_return_to_rest(run_sahp)

t_nosahp, v_nosahp = find_return_to_rest(run_nosahp)

# figura
plt.figure(figsize=(11,4))

# con sAHP
plt.plot(
    run_sahp["t"],
    run_sahp["v"],
    label="Con sAHP",
    linewidth=1.0,
    color="#8c2d2d"
)


# sin sAHP
plt.plot(
    run_nosahp["t"],
    run_nosahp["v"],
    label="Sin sAHP",
    linewidth=1.0,
    color="#3465a4"
)


# labels
plt.xlabel("Tiempo (ms)", fontsize=12)
plt.ylabel("Potencial de membrana (mV)", fontsize=12)

# límites
plt.xlim(250, 400)
plt.ylim(-75, -60)

# ticks
plt.tick_params(
    direction='out',
    length=5,
    width=1
)

# leyenda
plt.legend(frameon=False, fontsize = 14)

# quitar caja
sns.despine()
plt.axhline(
    y=-70,
    color="gray",
    linestyle=":",
    linewidth=0.8,
    alpha=0.3
)
plt.tight_layout()


plt.savefig(
    "figs/run_comparison.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()