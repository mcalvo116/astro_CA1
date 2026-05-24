# README: CA1 sAHP model

This is the README for the CA1 sAHP model.

## Abstract
The intrinsic excitability of hippocampal neurons depends on multiple ionic currents that regulate firing frequency and neuronal oscillatory dynamics. Among these, calcium-dependent afterhyperpolarization currents (IAHP), particularly the slow component (sAHP), play a central role in neuronal adaptation. Recent evidence further suggests that astrocytic activity may modulate these processes through slow calcium-dependent mechanisms. In this study, a multicompartmental computational model of a CA1 pyramidal neuron was developed in the NEURON simulation environment, incorporating voltage-dependent active mechanisms and a slow calcium-activated potassium current designed to reproduce the functional dynamics of the sAHP. Using this model, we explored the effects of different ionic conductances on neuronal excitability and implemented a simplified periodic modulation of calcium channels as a functional approximation of astrocytic signaling. The results show that small variations in intracellular calcium entry modulate the activation of sAHP currents and alter both firing frequency and the temporal dynamics of neuronal activity. Although the model is limited by its simplified representation and the absence of network dynamics, it provides a useful framework for the exploratory study of cellular mechanisms involved in the modulation of hippocampal oscillatory activity.

---
### Usage Instructions

Implemented in NEURON 8.2.0, using HOC language

**1.**  Download and extract the archive.

**2.**  To compile the mod files, use the mknrndll command.

**3.** Double click on any of the simulation files, e.g. *5a_onerun_astro_freq.hoc* to open the simulation window for reproducing results.
<br>
<br>
<br>

**Attention:**
- Not tested on NEURON for Linux/Unix or macOS

Questions on how to use this model should be directed to mariacalvo2800@gmail.com





