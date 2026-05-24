#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern "C" void _cacumm_reg();
extern "C" void _cad_reg();
extern "C" void _cagk_reg();
extern "C" void _cal2_reg();
extern "C" void _cat_reg();
extern "C" void _h_reg();
extern "C" void _kadist_reg();
extern "C" void _kadist_dopa_reg();
extern "C" void _KahpM95_reg();
extern "C" void _kaprox_reg();
extern "C" void _kdrca1_reg();
extern "C" void _km_reg();
extern "C" void _Ksahp_reg();
extern "C" void _na3n_reg();
extern "C" void _naxn_reg();
extern "C" void _nmdaCutsuridis_reg();
extern "C" void _STDPE2Syn_reg();

extern "C" void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," cacumm.mod");
fprintf(stderr," cad.mod");
fprintf(stderr," cagk.mod");
fprintf(stderr," cal2.mod");
fprintf(stderr," cat.mod");
fprintf(stderr," h.mod");
fprintf(stderr," kadist.mod");
fprintf(stderr," kadist_dopa.mod");
fprintf(stderr," KahpM95.mod");
fprintf(stderr," kaprox.mod");
fprintf(stderr," kdrca1.mod");
fprintf(stderr," km.mod");
fprintf(stderr," Ksahp.mod");
fprintf(stderr," na3n.mod");
fprintf(stderr," naxn.mod");
fprintf(stderr," nmdaCutsuridis.mod");
fprintf(stderr," STDPE2Syn.mod");
fprintf(stderr, "\n");
    }
_cacumm_reg();
_cad_reg();
_cagk_reg();
_cal2_reg();
_cat_reg();
_h_reg();
_kadist_reg();
_kadist_dopa_reg();
_KahpM95_reg();
_kaprox_reg();
_kdrca1_reg();
_km_reg();
_Ksahp_reg();
_na3n_reg();
_naxn_reg();
_nmdaCutsuridis_reg();
_STDPE2Syn_reg();
}
