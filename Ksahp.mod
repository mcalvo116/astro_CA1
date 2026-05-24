TITLE slow K-AHP channel (no Ca filter, monotonic decay)

NEURON {
    SUFFIX KsAHP
    USEION k READ ek WRITE ik
    USEION ca READ cai
    RANGE gbar, ik, gksahp
}

UNITS {
    (mA) = (milliamp)
    (mV) = (millivolt)
}

PARAMETER {
    gbar = 0.001 (mho/cm2)

    tau_rise = 100 (ms)    : subida relativamente rapida
    tau_decay = 800 (ms)   : bajada lenta (sAHP real)

    n = 4
    kD = 0.0004 (mM)

    cai0 = 50e-6 (mM)

    ek (mV)
}

STATE {
    w   : activacion del canal
}

ASSIGNED {
    ik (mA/cm2)
    gksahp (mho/cm2)
    cai (mM)
    winf
    ca_eff
}

BREAKPOINT {
    SOLVE states METHOD cnexp
    gksahp = gbar * w
    ik = gksahp * (v - ek)
}

INITIAL {
    w = 0
}

DERIVATIVE states {

    : Ca efectivo (solo por encima del basal)
    ca_eff = cai - cai0
    if (ca_eff < 0) {
        ca_eff = 0
    }

    : activacion tipo Hill
    winf = ca_eff^n / (ca_eff^n + kD^n)

    : cinetica asimetrica
    if (winf > w) {
        w' = (winf - w)/tau_rise
    } else {
        w' = (winf - w)/tau_decay
    }
}