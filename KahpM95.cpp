/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#define _pval pval
// clang-format off
#include "md1redef.h"
#include "section_fwd.hpp"
#include "nrniv_mf.h"
#include "md2redef.h"
#include "nrnconf.h"
// clang-format on
#include "neuron/cache/mechanism_range.hpp"
#include <vector>
using std::size_t;
static auto& std_cerr_stream = std::cerr;
static constexpr auto number_of_datum_variables = 5;
static constexpr auto number_of_floating_point_variables = 8;
namespace {
template <typename T>
using _nrn_mechanism_std_vector = std::vector<T>;
using _nrn_model_sorted_token = neuron::model_sorted_token;
using _nrn_mechanism_cache_range = neuron::cache::MechanismRange<number_of_floating_point_variables, number_of_datum_variables>;
using _nrn_mechanism_cache_instance = neuron::cache::MechanismInstance<number_of_floating_point_variables, number_of_datum_variables>;
using _nrn_non_owning_id_without_container = neuron::container::non_owning_identifier_without_container;
template <typename T>
using _nrn_mechanism_field = neuron::mechanism::field<T>;
template <typename... Args>
void _nrn_mechanism_register_data_fields(Args&&... args) {
  neuron::mechanism::register_data_fields(std::forward<Args>(args)...);
}
}
 
#if !NRNGPU
#undef exp
#define exp hoc_Exp
#if NRN_ENABLE_ARCH_INDEP_EXP_POW
#undef pow
#define pow hoc_pow
#endif
#endif
 
#define nrn_init _nrn_init__KahpM95
#define _nrn_initial _nrn_initial__KahpM95
#define nrn_cur _nrn_cur__KahpM95
#define _nrn_current _nrn_current__KahpM95
#define nrn_jacob _nrn_jacob__KahpM95
#define nrn_state _nrn_state__KahpM95
#define _net_receive _net_receive__KahpM95 
#define rate rate__KahpM95 
#define state state__KahpM95 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _internalthreadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
#define _internalthreadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *hoc_getarg(int);
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gbar _ml->template fpfield<0>(_iml)
#define gbar_columnindex 0
#define ik _ml->template fpfield<1>(_iml)
#define ik_columnindex 1
#define gkahp _ml->template fpfield<2>(_iml)
#define gkahp_columnindex 2
#define w _ml->template fpfield<3>(_iml)
#define w_columnindex 3
#define cai _ml->template fpfield<4>(_iml)
#define cai_columnindex 4
#define ek _ml->template fpfield<5>(_iml)
#define ek_columnindex 5
#define Dw _ml->template fpfield<6>(_iml)
#define Dw_columnindex 6
#define _g _ml->template fpfield<7>(_iml)
#define _g_columnindex 7
#define _ion_ek *(_ml->dptr_field<0>(_iml))
#define _p_ion_ek static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_ik *(_ml->dptr_field<1>(_iml))
#define _p_ion_ik static_cast<neuron::container::data_handle<double>>(_ppvar[1])
#define _ion_dikdv *(_ml->dptr_field<2>(_iml))
#define _ion_cai *(_ml->dptr_field<3>(_iml))
#define _p_ion_cai static_cast<neuron::container::data_handle<double>>(_ppvar[3])
#define _ion_cao *(_ml->dptr_field<4>(_iml))
#define _p_ion_cao static_cast<neuron::container::data_handle<double>>(_ppvar[4])
 static _nrn_mechanism_cache_instance _ml_real{nullptr};
static _nrn_mechanism_cache_range *_ml{&_ml_real};
static size_t _iml{0};
static Datum *_ppvar;
 static int hoc_nrnpointerindex =  -1;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alp(void);
 static void _hoc_rate(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mechtype);
#endif
 static void _hoc_setdata();
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 {"setdata_KahpM95", _hoc_setdata},
 {"alp_KahpM95", _hoc_alp},
 {"rate_KahpM95", _hoc_rate},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_alp(Prop*);
 static double _npy_rate(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"alp", _npy_alp},
 {"rate", _npy_rate},
 {0, 0}
};
#define alp alp_KahpM95
 extern double alp( double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
#define a0 a0_KahpM95
 double a0 = 1e+08;
#define b0 b0_KahpM95
 double b0 = 0.005;
#define inf inf_KahpM95
 double inf = 0;
#define n n_KahpM95
 double n = 4;
#define q10 q10_KahpM95
 double q10 = 3;
#define tau tau_KahpM95
 double tau = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"a0_KahpM95", "/ms-mM-mM-mM-mM"},
 {"b0_KahpM95", "/ms"},
 {"gbar_KahpM95", "mho/cm2"},
 {"ik_KahpM95", "mA/cm2"},
 {"gkahp_KahpM95", "mho/cm2"},
 {0, 0}
};
 static double delta_t = 0.01;
 static double v = 0;
 static double w0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {"n_KahpM95", &n_KahpM95},
 {"a0_KahpM95", &a0_KahpM95},
 {"b0_KahpM95", &b0_KahpM95},
 {"q10_KahpM95", &q10_KahpM95},
 {"inf_KahpM95", &inf_KahpM95},
 {"tau_KahpM95", &tau_KahpM95},
 {0, 0}
};
 static DoubVec hoc_vdoub[] = {
 {0, 0, 0}
};
 static double _sav_indep;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 _prop_id = _nrn_get_prop_id(_prop);
 neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
_ppvar = _nrn_mechanism_access_dparam(_prop);
 Node * _node = _nrn_mechanism_access_node(_prop);
v = _nrn_mechanism_access_voltage(_node);
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 static void nrn_alloc(Prop*);
static void nrn_init(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_state(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void nrn_cur(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_jacob(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(Prop*, int, neuron::container::data_handle<double>*, neuron::container::data_handle<double>*, double*, int);
static void _ode_spec(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void _ode_matsol(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
#define _cvode_ieq _ppvar[5].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"KahpM95",
 "gbar_KahpM95",
 0,
 "ik_KahpM95",
 "gkahp_KahpM95",
 0,
 "w_KahpM95",
 0,
 0};
 static Symbol* _k_sym;
 static Symbol* _ca_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0.003, /* gbar */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 8);
 	/*initialize range parameters*/
 	gbar = _parm_default[0]; /* 0.003 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 8);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ek */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ik */
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dikdv */
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[3] = _nrn_mechanism_get_param_handle(prop_ion, 1); /* cai */
 	_ppvar[4] = _nrn_mechanism_get_param_handle(prop_ion, 2); /* cao */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 {0, 0}
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _KahpM95_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	ion_reg("ca", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gbar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"ik"} /* 1 */,
                                       _nrn_mechanism_field<double>{"gkahp"} /* 2 */,
                                       _nrn_mechanism_field<double>{"w"} /* 3 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 4 */,
                                       _nrn_mechanism_field<double>{"ek"} /* 5 */,
                                       _nrn_mechanism_field<double>{"Dw"} /* 6 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 7 */,
                                       _nrn_mechanism_field<double*>{"_ion_ek", "k_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_ik", "k_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_dikdv", "k_ion"} /* 2 */,
                                       _nrn_mechanism_field<double*>{"_ion_cai", "ca_ion"} /* 3 */,
                                       _nrn_mechanism_field<double*>{"_ion_cao", "ca_ion"} /* 4 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 5 */);
  hoc_register_prop_size(_mechtype, 8, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 KahpM95 C\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "Borg-Graham type generic K-AHP channel -- mAHP, dependiente de Ca directo (representado por cai: corriente de calcio)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rate(double);
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static neuron::container::field_index _slist1[1], _dlist1[1];
 static int state(_internalthreadargsproto_);
 
double alp (  double _lcai ) {
   double _lalp;
 _lalp = a0 * pow( _lcai , n ) ;
   
return _lalp;
 }
 
static void _hoc_alp(void) {
  double _r;
    _r =  alp (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alp(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
 _r =  alp (  *getarg(1) );
 return(_r);
}
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rate ( _threadargscomma_ cai ) ;
   Dw = ( inf - w ) / tau ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rate ( _threadargscomma_ cai ) ;
 Dw = Dw  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau )) ;
  return 0;
}
 /*END CVODE*/
 static int state () {_reset=0;
 {
   rate ( _threadargscomma_ cai ) ;
    w = w + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau)))*(- ( ( ( inf ) ) / tau ) / ( ( ( ( - 1.0 ) ) ) / tau ) - w) ;
   }
  return 0;
}
 
static int  rate (  double _lcai ) {
   double _la , _lqt ;
 _lqt = pow( q10 , ( ( celsius - 24.0 ) / 10.0 ) ) ;
   _la = alp ( _threadargscomma_ _lcai ) ;
   tau = 1.0 / ( _lqt * ( _la + b0 ) ) ;
   inf = _la * tau * _lqt ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
    _r = 1.;
 rate (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_rate(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
 _r = 1.;
 rate (  *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
      Node* _nd{};
  double _v{};
  int _cntml;
  _nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
  _ml = &_lmr;
  _cntml = _ml_arg->_nodecount;
  Datum *_thread{_ml_arg->_thread};
  double* _globals = nullptr;
  if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _ppvar = _ml_arg->_pdata[_iml];
    _nd = _ml_arg->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
  cai = _ion_cai;
     _ode_spec1 ();
  }}
 
static void _ode_map(Prop* _prop, int _ieq, neuron::container::data_handle<double>* _pv, neuron::container::data_handle<double>* _pvdot, double* _atol, int _type) { 
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  _cvode_ieq = _ieq;
  for (int _i=0; _i < 1; ++_i) {
    _pv[_i] = _nrn_mechanism_get_param_handle(_prop, _slist1[_i]);
    _pvdot[_i] = _nrn_mechanism_get_param_handle(_prop, _dlist1[_i]);
    _cvode_abstol(_atollist, _atol, _i);
  }
 }
 
static void _ode_matsol_instance1(_internalthreadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
      Node* _nd{};
  double _v{};
  int _cntml;
  _nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
  _ml = &_lmr;
  _cntml = _ml_arg->_nodecount;
  Datum *_thread{_ml_arg->_thread};
  double* _globals = nullptr;
  if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _ppvar = _ml_arg->_pdata[_iml];
    _nd = _ml_arg->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  w = w0;
 {
   rate ( _threadargscomma_ cai ) ;
   w = inf ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
Node *_nd; double _v; int* _ni; int _cntml;
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 v = _v;
  ek = _ion_ek;
  cai = _ion_cai;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gkahp = gbar * w ;
   ik = gkahp * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_rhs = _nt->node_rhs_storage();
auto const _vec_sav_rhs = _nt->node_sav_rhs_storage();
auto const _vec_v = _nt->node_voltage_storage();
Node *_nd; int* _ni; double _rhs, _v; int _cntml;
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
  ek = _ion_ek;
  cai = _ion_cai;
 auto const _g_local = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ik += ik ;
	 _vec_rhs[_ni[_iml]] -= _rhs;
 
}}

static void nrn_jacob(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_d = _nt->node_d_storage();
auto const _vec_sav_d = _nt->node_sav_d_storage();
auto* const _ml = &_lmr;
Node *_nd; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
  _vec_d[_ni[_iml]] += _g;
 
}}

static void nrn_state(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _cntml;
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
 _nd = _ml_arg->_nodelist[_iml];
   _v = _vec_v[_ni[_iml]];
 v=_v;
{
  ek = _ion_ek;
  cai = _ion_cai;
 { error =  state();
 if(error){
  std_cerr_stream << "at line 39 in file KahpM95.mod:\nBREAKPOINT {\n";
  std_cerr_stream << _ml << ' ' << _iml << '\n';
  abort_run(error);
}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {w_columnindex, 0};  _dlist1[0] = {Dw_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "C";
    const char* nmodl_file_text = 
  ":Migliore file Modify by Maciej Lazarewicz (mailto:mlazarew@gmu.edu) May/16/2001\n"
  "\n"
  "TITLE Borg-Graham type generic K-AHP channel -- mAHP, dependiente de Ca directo (representado por cai: corriente de calcio)\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX KahpM95\n"
  "	USEION k READ ek WRITE ik\n"
  "        USEION ca READ cai\n"
  "        RANGE  gbar,ik, gkahp\n"
  "        GLOBAL inf,tau\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	celsius = 6.3	(degC)\n"
  "	gbar	= .003 	(mho/cm2)\n"
  "        n	= 4\n"
  "        cai	= 50.e-6 (mM)\n"
  "        a0	= 1e8 (/ms-mM-mM-mM-mM)		:b0/(20e-4^4)\n"
  "        b0	= .5e-2  (/ms)			:0.5/(0.100e3)\n"
  "        v       	 (mV)\n"
  "        ek      	 (mV)\n"
  "	q10=3\n"
  "}\n"
  "\n"
  "STATE {	w }\n"
  "\n"
  "ASSIGNED {\n"
  "	ik 		(mA/cm2)\n"
  "        gkahp  		(mho/cm2)\n"
  "        inf\n"
  "        tau\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE state METHOD cnexp\n"
  "	gkahp = gbar*w\n"
  "	ik = gkahp*(v-ek)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	rate(cai)\n"
  "	w=inf\n"
  "}\n"
  "\n"
  "FUNCTION alp(cai (mM)) {\n"
  "  alp = a0*cai^n\n"
  "}\n"
  "\n"
  "DERIVATIVE state {     : exact when v held constant; integrates over dt step\n"
  "        rate(cai)\n"
  "        w' = (inf - w)/tau\n"
  "}\n"
  "\n"
  "PROCEDURE rate(cai (mM)) { :callable from hoc\n"
  "        LOCAL a,qt\n"
  "        qt=q10^((celsius-24)/10)\n"
  "        a = alp(cai)\n"
  "        tau = 1/(qt*(a + b0))\n"
  "        inf = a*tau*qt\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
