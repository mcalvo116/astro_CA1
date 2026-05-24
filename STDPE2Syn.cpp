/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
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
static constexpr auto number_of_datum_variables = 2;
static constexpr auto number_of_floating_point_variables = 28;
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
 
#define nrn_init _nrn_init__STDPE2mio
#define _nrn_initial _nrn_initial__STDPE2mio
#define nrn_cur _nrn_cur__STDPE2mio
#define _nrn_current _nrn_current__STDPE2mio
#define nrn_jacob _nrn_jacob__STDPE2mio
#define nrn_state _nrn_state__STDPE2mio
#define _net_receive _net_receive__STDPE2mio 
#define state state__STDPE2mio 
 
#define _threadargscomma_ _ml, _iml, _ppvar, _thread, _globals, _nt,
#define _threadargsprotocomma_ Memb_list* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt,
#define _internalthreadargsprotocomma_ _nrn_mechanism_cache_range* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt,
#define _threadargs_ _ml, _iml, _ppvar, _thread, _globals, _nt
#define _threadargsproto_ Memb_list* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt
#define _internalthreadargsproto_ _nrn_mechanism_cache_range* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *hoc_getarg(int);
 
#define t _nt->_t
#define dt _nt->_dt
#define tau1 _ml->template fpfield<0>(_iml)
#define tau1_columnindex 0
#define tau2 _ml->template fpfield<1>(_iml)
#define tau2_columnindex 1
#define e _ml->template fpfield<2>(_iml)
#define e_columnindex 2
#define wmax _ml->template fpfield<3>(_iml)
#define wmax_columnindex 3
#define wmin _ml->template fpfield<4>(_iml)
#define wmin_columnindex 4
#define d _ml->template fpfield<5>(_iml)
#define d_columnindex 5
#define p _ml->template fpfield<6>(_iml)
#define p_columnindex 6
#define dM _ml->template fpfield<7>(_iml)
#define dM_columnindex 7
#define dV _ml->template fpfield<8>(_iml)
#define dV_columnindex 8
#define ptau _ml->template fpfield<9>(_iml)
#define ptau_columnindex 9
#define thresh _ml->template fpfield<10>(_iml)
#define thresh_columnindex 10
#define gbdel _ml->template fpfield<11>(_iml)
#define gbdel_columnindex 11
#define gbint _ml->template fpfield<12>(_iml)
#define gbint_columnindex 12
#define gblen _ml->template fpfield<13>(_iml)
#define gblen_columnindex 13
#define gscale _ml->template fpfield<14>(_iml)
#define gscale_columnindex 14
#define i _ml->template fpfield<15>(_iml)
#define i_columnindex 15
#define g _ml->template fpfield<16>(_iml)
#define g_columnindex 16
#define factor _ml->template fpfield<17>(_iml)
#define factor_columnindex 17
#define C _ml->template fpfield<18>(_iml)
#define C_columnindex 18
#define B _ml->template fpfield<19>(_iml)
#define B_columnindex 19
#define tpost _ml->template fpfield<20>(_iml)
#define tpost_columnindex 20
#define on _ml->template fpfield<21>(_iml)
#define on_columnindex 21
#define gs _ml->template fpfield<22>(_iml)
#define gs_columnindex 22
#define DC _ml->template fpfield<23>(_iml)
#define DC_columnindex 23
#define DB _ml->template fpfield<24>(_iml)
#define DB_columnindex 24
#define v _ml->template fpfield<25>(_iml)
#define v_columnindex 25
#define _g _ml->template fpfield<26>(_iml)
#define _g_columnindex 26
#define _tsav _ml->template fpfield<27>(_iml)
#define _tsav_columnindex 27
#define _nd_area *_ml->dptr_field<0>(_iml)
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mechtype);
#endif
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 static void _hoc_setdata(void*);
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 {0, 0}
};
 static Member_func _member_func[] = {
 {"loc", _hoc_loc_pnt},
 {"has_loc", _hoc_has_loc},
 {"get_loc", _hoc_get_loc_pnt},
 {0, 0}
};
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
#define pi pi_STDPE2mio
 double pi = 3.14159;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"gbint", 1e-09, 1e+09},
 {"gblen", 1e-09, 1e+09},
 {"gbdel", 1e-09, 1e+09},
 {"tau2", 1e-09, 1e+09},
 {"tau1", 1e-09, 1e+09},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"tau1", "ms"},
 {"tau2", "ms"},
 {"e", "mV"},
 {"wmax", "uS"},
 {"wmin", "uS"},
 {"dM", "ms"},
 {"dV", "ms"},
 {"ptau", "ms"},
 {"thresh", "mV"},
 {"gbdel", "ms"},
 {"gbint", "ms"},
 {"gblen", "ms"},
 {"C", "uS"},
 {"B", "uS"},
 {"i", "nA"},
 {"g", "uS"},
 {0, 0}
};
 static double B0 = 0;
 static double C0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {"pi_STDPE2mio", &pi_STDPE2mio},
 {0, 0}
};
 static DoubVec hoc_vdoub[] = {
 {0, 0, 0}
};
 static double _sav_indep;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 static void nrn_alloc(Prop*);
static void nrn_init(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_state(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void nrn_cur(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_jacob(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
#define _watch_array _ppvar + 3 
 static void _watch_alloc(Datum*);
 extern void hoc_reg_watch_allocate(int, void(*)(Datum*)); 
#define _fnc_index 5
 static void _hoc_destroy_pnt(void* _vptr) {
   Prop* _prop = ((Point_process*)_vptr)->_prop;
   if (_prop) { _nrn_free_watch(_nrn_mechanism_access_dparam(_prop), 3, 2);}
   if (_prop) { _nrn_free_fornetcon(&(_nrn_mechanism_access_dparam(_prop)[_fnc_index].literal_value<void*>()));}
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(Prop*, int, neuron::container::data_handle<double>*, neuron::container::data_handle<double>*, double*, int);
static void _ode_spec(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void _ode_matsol(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
#define _cvode_ieq _ppvar[6].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"STDPE2mio",
 "tau1",
 "tau2",
 "e",
 "wmax",
 "wmin",
 "d",
 "p",
 "dM",
 "dV",
 "ptau",
 "thresh",
 "gbdel",
 "gbint",
 "gblen",
 "gscale",
 0,
 "i",
 "g",
 "factor",
 0,
 "C",
 "B",
 0,
 0};
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0.5, /* tau1 */
     3, /* tau2 */
     0, /* e */
     0.002, /* wmax */
     0.0001, /* wmin */
     0.26, /* d */
     0.8, /* p */
     -12, /* dM */
     6.32, /* dV */
     3, /* ptau */
     -20, /* thresh */
     50, /* gbdel */
     125, /* gbint */
     125, /* gblen */
     1, /* gscale */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
  if (nrn_point_prop_) {
    _nrn_mechanism_access_alloc_seq(_prop) = _nrn_mechanism_access_alloc_seq(nrn_point_prop_);
    _ppvar = _nrn_mechanism_access_dparam(nrn_point_prop_);
  } else {
   _ppvar = nrn_prop_datum_alloc(_mechtype, 7, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 28);
 	/*initialize range parameters*/
 	tau1 = _parm_default[0]; /* 0.5 */
 	tau2 = _parm_default[1]; /* 3 */
 	e = _parm_default[2]; /* 0 */
 	wmax = _parm_default[3]; /* 0.002 */
 	wmin = _parm_default[4]; /* 0.0001 */
 	d = _parm_default[5]; /* 0.26 */
 	p = _parm_default[6]; /* 0.8 */
 	dM = _parm_default[7]; /* -12 */
 	dV = _parm_default[8]; /* 6.32 */
 	ptau = _parm_default[9]; /* 3 */
 	thresh = _parm_default[10]; /* -20 */
 	gbdel = _parm_default[11]; /* 50 */
 	gbint = _parm_default[12]; /* 125 */
 	gblen = _parm_default[13]; /* 125 */
 	gscale = _parm_default[14]; /* 1 */
  }
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 28);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 {0, 0}
};
 
#define _tqitem &(_ppvar[2])
 static void _net_receive(Point_process*, double*, double);
 extern int _nrn_netcon_args(void*, double***);
 static void _net_init(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _STDPE2Syn_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"tau1"} /* 0 */,
                                       _nrn_mechanism_field<double>{"tau2"} /* 1 */,
                                       _nrn_mechanism_field<double>{"e"} /* 2 */,
                                       _nrn_mechanism_field<double>{"wmax"} /* 3 */,
                                       _nrn_mechanism_field<double>{"wmin"} /* 4 */,
                                       _nrn_mechanism_field<double>{"d"} /* 5 */,
                                       _nrn_mechanism_field<double>{"p"} /* 6 */,
                                       _nrn_mechanism_field<double>{"dM"} /* 7 */,
                                       _nrn_mechanism_field<double>{"dV"} /* 8 */,
                                       _nrn_mechanism_field<double>{"ptau"} /* 9 */,
                                       _nrn_mechanism_field<double>{"thresh"} /* 10 */,
                                       _nrn_mechanism_field<double>{"gbdel"} /* 11 */,
                                       _nrn_mechanism_field<double>{"gbint"} /* 12 */,
                                       _nrn_mechanism_field<double>{"gblen"} /* 13 */,
                                       _nrn_mechanism_field<double>{"gscale"} /* 14 */,
                                       _nrn_mechanism_field<double>{"i"} /* 15 */,
                                       _nrn_mechanism_field<double>{"g"} /* 16 */,
                                       _nrn_mechanism_field<double>{"factor"} /* 17 */,
                                       _nrn_mechanism_field<double>{"C"} /* 18 */,
                                       _nrn_mechanism_field<double>{"B"} /* 19 */,
                                       _nrn_mechanism_field<double>{"tpost"} /* 20 */,
                                       _nrn_mechanism_field<double>{"on"} /* 21 */,
                                       _nrn_mechanism_field<double>{"gs"} /* 22 */,
                                       _nrn_mechanism_field<double>{"DC"} /* 23 */,
                                       _nrn_mechanism_field<double>{"DB"} /* 24 */,
                                       _nrn_mechanism_field<double>{"v"} /* 25 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 26 */,
                                       _nrn_mechanism_field<double>{"_tsav"} /* 27 */,
                                       _nrn_mechanism_field<double*>{"_nd_area", "area"} /* 0 */,
                                       _nrn_mechanism_field<Point_process*>{"_pntproc", "pntproc"} /* 1 */,
                                       _nrn_mechanism_field<void*>{"_tqitem", "netsend"} /* 2 */,
                                       _nrn_mechanism_field<void*>{"_watch_array", "watch"} /* 3 */,
                                       _nrn_mechanism_field<void*>{"_watch_array", "watch"} /* 4 */,
                                       _nrn_mechanism_field<void*>{"_fnc_index", "fornetcon"} /* 5 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 6 */);
  hoc_register_prop_size(_mechtype, 28, 7);
  hoc_reg_watch_allocate(_mechtype, _watch_alloc);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "netsend");
  hoc_register_dparam_semantics(_mechtype, 3, "watch");
  hoc_register_dparam_semantics(_mechtype, 4, "watch");
  hoc_register_dparam_semantics(_mechtype, 5, "fornetcon");
  hoc_register_dparam_semantics(_mechtype, 6, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_init[_mechtype] = _net_init;
 pnt_receive_size[_mechtype] = 3;
 add_nrn_fornetcons(_mechtype, _fnc_index);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 STDPE2mio C\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static neuron::container::field_index _slist1[2], _dlist1[2];
 static int state(_internalthreadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (_internalthreadargsproto_) {int _reset = 0; {
   DC = - C / tau1 ;
   DB = - B / tau2 ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 DC = DC  / (1. - dt*( ( - 1.0 ) / tau1 )) ;
 DB = DB  / (1. - dt*( ( - 1.0 ) / tau2 )) ;
  return 0;
}
 /*END CVODE*/
 static int state (_internalthreadargsproto_) { {
    C = C + (1. - exp(dt*(( - 1.0 ) / tau1)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau1 ) - C) ;
    B = B + (1. - exp(dt*(( - 1.0 ) / tau2)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau2 ) - B) ;
   }
  return 0;
}
 
static double _watch1_cond(Point_process* _pnt) {
   Datum* _ppvar; Datum* _thread{};
  NrnThread* _nt{static_cast<NrnThread*>(_pnt->_vnt)};
   auto* const _prop = _pnt->_prop;
  _nrn_mechanism_cache_instance _ml_real{_prop};
  auto* const _ml = &_ml_real;
  size_t _iml{};
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  v = NODEV(_pnt->node);
	return  ( v ) - ( thresh ) ;
}
 
static void _net_receive (Point_process* _pnt, double* _args, double _lflag) 
{  Prop* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   int _watch_rm = 0;
   _nrn_mechanism_cache_instance _ml_real{_pnt->_prop};
  auto* const _ml = &_ml_real;
  size_t const _iml{};
   _thread = nullptr; double* _globals = nullptr; _nt = (NrnThread*)_pnt->_vnt;   _ppvar = _nrn_mechanism_access_dparam(_pnt->_prop);
  if (_tsav > t){ hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = nullptr;}
 {
   if ( _lflag  == 0.0 ) {
     printf ( "presynaptic spike t=%g w=%g A=%g tpre=%g tpost=%g\n" , t , _args[0] , _args[1] , _args[2] , tpost ) ;
       if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = C;
    double __primary = (C + ( _args[0] + _args[1] ) * factor) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau1 ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau1 ) - __primary );
    C += __primary;
  } else {
 C = C + ( _args[0] + _args[1] ) * factor ;
       }
   if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = B;
    double __primary = (B + ( _args[0] + _args[1] ) * factor) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau2 ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau2 ) - __primary );
    B += __primary;
  } else {
 B = B + ( _args[0] + _args[1] ) * factor ;
       }
 printf ( " B %f\t C %f\t w %f\n" , B , C , _args[0] ) ;
     _args[2] = t ;
     if ( on  == 1.0 ) {
       _args[1] = _args[1] * ( 1.0 - ( d * exp ( - pow( ( ( tpost - t ) - dM ) , 2.0 ) / ( 2.0 * dV * dV ) ) ) ) ;
       printf ( "%g %g\n" , t ) ;
       }
     }
   else if ( _lflag  == 2.0  && on  == 1.0 ) {
     printf ( "entry flag=%g t=%g tpost=%g\n" , _lflag , t , tpost ) ;
     tpost = t ;
     {int _ifn1, _nfn1; double* _fnargs1, **_fnargslist1;
	_nfn1 = _nrn_netcon_args(_ppvar[_fnc_index].get<void*>(), &_fnargslist1);
	for (_ifn1 = 0; _ifn1 < _nfn1; ++_ifn1) {
 	 _fnargs1 = _fnargslist1[_ifn1];
 {
       printf ( "entry FOR_NETCONS w1=%g A1=%g tp=%g t=%g\n" , _fnargs1[0] , _fnargs1[1] , _fnargs1[2] , t ) ;
       _fnargs1[1] = _fnargs1[1] + ( 2.0 * _fnargs1[0] - _fnargs1[0] - _fnargs1[1] ) * p * exp ( ( _fnargs1[2] - t ) / ptau ) ;
       printf ( "%g %g\n" , t , _fnargs1[1] ) ;
       }
     	}}
 }
   else if ( _lflag  == 1.0 ) {
     printf ( "entry flag=%g t=%g\n" , _lflag , t ) ;
       _nrn_watch_activate(_watch_array, _watch1_cond, 1, _pnt, _watch_rm++, 2.0);
 }
   else if ( _lflag  == 3.0 ) {
     if ( on  == 0.0 ) {
       on = 1.0 ;
       gs = gscale ;
       net_send ( _tqitem, _args, _pnt, t +  gblen , 3.0 ) ;
       }
     else {
       on = 0.0 ;
       gs = 1.0 ;
       net_send ( _tqitem, _args, _pnt, t +  gbint , 3.0 ) ;
       }
     }
   } }
 
static void _net_init(Point_process* _pnt, double* _args, double _lflag) {
     _nrn_mechanism_cache_instance _ml_real{_pnt->_prop};
  auto* const _ml = &_ml_real;
  size_t const _iml{};
  Datum* _ppvar = _nrn_mechanism_access_dparam(_pnt->_prop);
  Datum* _thread = nullptr;
  double* _globals = nullptr;
  NrnThread* _nt = (NrnThread*)_pnt->_vnt;
 _args[1] = 0.0 ;
   _args[2] = - 1e9 ;
   }
 
static void _watch_alloc(Datum* _ppvar) {
  auto* _pnt = _ppvar[1].get<Point_process*>();
   _nrn_watch_allocate(_watch_array, _watch1_cond, 1, _pnt, 2.0);
 }

 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
   Datum* _ppvar;
   size_t _iml;   _nrn_mechanism_cache_range* _ml;   Node* _nd{};
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
     _ode_spec1 (_threadargs_);
 }}
 
static void _ode_map(Prop* _prop, int _ieq, neuron::container::data_handle<double>* _pv, neuron::container::data_handle<double>* _pvdot, double* _atol, int _type) { 
  Datum* _ppvar;
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  _cvode_ieq = _ieq;
  for (int _i=0; _i < 2; ++_i) {
    _pv[_i] = _nrn_mechanism_get_param_handle(_prop, _slist1[_i]);
    _pvdot[_i] = _nrn_mechanism_get_param_handle(_prop, _dlist1[_i]);
    _cvode_abstol(_atollist, _atol, _i);
  }
 }
 
static void _ode_matsol_instance1(_internalthreadargsproto_) {
 _ode_matsol1 (_threadargs_);
 }
 
static void _ode_matsol(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
   Datum* _ppvar;
   size_t _iml;   _nrn_mechanism_cache_range* _ml;   Node* _nd{};
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
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
  B = B0;
  C = C0;
 {
   double _ltp ;
 if ( tau1 / tau2 > .9999 ) {
     tau1 = .9999 * tau2 ;
     }
   C = 0.0 ;
   B = 0.0 ;
   _ltp = ( tau1 * tau2 ) / ( tau2 - tau1 ) * log ( tau2 / tau1 ) ;
   factor = - exp ( - _ltp / tau1 ) + exp ( - _ltp / tau2 ) ;
   factor = 1.0 / factor ;
   gs = 1.0 ;
   on = 1.0 ;
   tpost = - 1e9 ;
   net_send ( _tqitem, nullptr, _ppvar[1].get<Point_process*>(), t +  0.0 , 1.0 ) ;
   }
 
}
}

static void nrn_init(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
 _tsav = -1e20;
   _v = _vec_v[_ni[_iml]];
 v = _v;
 initmodel(_threadargs_);
}
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   g = B - C ;
   i = g * gs * ( v - e ) ;
   }
 _current += i;

} return _current;
}

static void nrn_cur(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_rhs = _nt->node_rhs_storage();
auto const _vec_sav_rhs = _nt->node_sav_rhs_storage();
auto const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 auto const _g_local = _nrn_current(_threadargscomma_ _v + .001);
 	{ _rhs = _nrn_current(_threadargscomma_ _v);
 	}
 _g = (_g_local - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
	 _vec_rhs[_ni[_iml]] -= _rhs;
 
}
 
}

static void nrn_jacob(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_d = _nt->node_d_storage();
auto const _vec_sav_d = _nt->node_sav_d_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
  _vec_d[_ni[_iml]] += _g;
 
}
 
}

static void nrn_state(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni;
_ni = _ml_arg->_nodeindices;
size_t _cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (size_t _iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
 _nd = _ml_arg->_nodelist[_iml];
   _v = _vec_v[_ni[_iml]];
 v=_v;
{
 {   state(_threadargs_);
  }}}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {C_columnindex, 0};  _dlist1[0] = {DC_columnindex, 0};
 _slist1[1] = {B_columnindex, 0};  _dlist1[1] = {DB_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "C";
    const char* nmodl_file_text = 
  ": STDP by Hines, changed to dual exponential (BPG 6-1-09)\n"
  ": Modified by BPG 13-12-08\n"
  ": Limited weights: max weight is wmax and min weight is wmin\n"
  ": (initial weight is specified by netconn - usually set to wmin)\n"
  ": Rhythmic GABAB suppresses conductance and promotes plasticity.\n"
  ": When GABAB is low, conductance is high and plasticity is off.\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	POINT_PROCESS STDPE2mio\n"
  "	RANGE tau1, tau2, e, i, d, p, dtau, ptau, thresh, wmax, wmin, srcnt1, srcnt2, srcnt3, srcnt4\n"
  "	RANGE g, gbdel, gblen, gbint, gscale, factor,dshift,dM,dV,B,C\n"
  "	NONSPECIFIC_CURRENT i\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(nA) = (nanoamp)\n"
  "	(mV) = (millivolt)\n"
  "	(uS) = (microsiemens)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	tau1=.5 (ms) <1e-9,1e9>\n"
  "	tau2 = 3 (ms) <1e-9,1e9>\n"
  "	e = 0	(mV)\n"
  "     pi=3.14159\n"
  "	wmax = 0.002 (uS)\n"
  "      :wmax = 0.0034 (uS)\n"
  "	wmin = 0.0001 (uS)	: not used - use netconn weight instead (BPG)\n"
  "	d = 0.26 : depression factor (multiplicative to prevent < 0)\n"
  "	p = 0.8 : potentiation factor (additive, non-saturating)\n"
  "	\n"
  "      dM = -12   (ms)\n"
  "       dV= 6.32    (ms)\n"
  "	 ptau = 3 (ms) : Nishiyama2000\n"
  "\n"
  "	:thresh = -9 (mV)	: postsynaptic voltage threshold\n"
  "      thresh = -20 (mV)	: postsynaptic voltage threshold\n"
  "	gbdel = 50 (ms) <1e-9,1e9> : initial GABAB off interval (ms)\n"
  "	gbint = 125 (ms) <1e-9,1e9> : GABAB off interval (ms)\n"
  "	gblen = 125 (ms) <1e-9,1e9> : GABAB on length (ms)\n"
  "	gscale = 1	: relative suppression by GABAB\n"
  "\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v (mV)\n"
  "	i (nA)\n"
  "	tpost (ms)\n"
  "	on\n"
  "	g (uS)\n"
  "	gs\n"
  "	factor\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	C (uS)\n"
  "	B (uS)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	LOCAL tp\n"
  "	if (tau1/tau2 > .9999) {\n"
  "		tau1 = .9999*tau2\n"
  "	}\n"
  "	C = 0\n"
  "	B = 0\n"
  "	tp = (tau1*tau2)/(tau2 - tau1) * log(tau2/tau1)\n"
  "	factor = -exp(-tp/tau1) + exp(-tp/tau2)\n"
  "	factor = 1/factor    \n"
  "	gs=1\n"
  "	on=1	: initially not plastic\n"
  "	tpost = -1e9\n"
  "	net_send(0, 1)\n"
  "	:net_send(gbdel, 3)	: initial GABAB off period\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE state METHOD cnexp\n"
  "	g = B - C\n"
  "     	i = g*gs*(v - e)\n"
  "    \n"
  "}\n"
  "\n"
  "DERIVATIVE state {\n"
  "	C' = -C/tau1\n"
  "	B' = -B/tau2\n"
  "}\n"
  "\n"
  "\n"
  "NET_RECEIVE(w (uS), A, tpre (ms) ) {\n"
  "	INITIAL { A = 0  tpre = -1e9 }\n"
  "	if (flag == 0) { : presynaptic spike  (after last post so depress)\n"
  "		printf(\"presynaptic spike t=%g w=%g A=%g tpre=%g tpost=%g\\n\", t, w, A, tpre, tpost)\n"
  ":		g = g + w + A	: only for single exp (BPG)\n"
  "		C = C + (w + A)*factor\n"
  "		B = B + (w + A)*factor\n"
  "          	printf(\" B %f\\t C %f\\t w %f\\n\",B, C, w)\n"
  "		tpre = t\n"
  "		if (on == 1) {\n"
  "			A = A * (1-(d*exp(-((tpost-t)-dM)^2/(2*dV*dV))))\n"
  "			printf(\"%g %g\\n\", t)\n"
  "		}\n"
  "	}else if (flag == 2 && on == 1) { : postsynaptic spike\n"
  "		printf(\"entry flag=%g t=%g tpost=%g\\n\", flag, t, tpost)\n"
  "		tpost = t\n"
  "            FOR_NETCONS(w1, A1, tp) { : also can hide NET_RECEIVE args\n"
  "			printf(\"entry FOR_NETCONS w1=%g A1=%g tp=%g t=%g\\n\", w1, A1, tp, t)\n"
  "			A1 = A1 + (2*w1-w1-A1)*p*exp((tp - t)/ptau)\n"
  "			printf(\"%g %g\\n\", t, A1)\n"
  "			}\n"
  "	} else if (flag == 1) { : flag == 1 from INITIAL block\n"
  "		printf(\"entry flag=%g t=%g\\n\", flag, t)\n"
  "		WATCH (v > thresh) 2\n"
  "	}\n"
  "	else if (flag == 3) { : plasticity control\n"
  "		if (on == 0) { : start plasticity\n"
  "			on = 1\n"
  "			gs = gscale\n"
  "			net_send(gblen, 3)\n"
  "		}\n"
  "		else { : end burst\n"
  "			on = 0\n"
  "			gs = 1\n"
  "			net_send(gbint, 3)\n"
  "		}\n"
  "	}\n"
  "}\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
