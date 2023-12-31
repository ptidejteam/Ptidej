/***** CLAIRE Compilation of file d:\claire\v3.2\src\compile\ocall.cl 
         [version 3.2.52 / safety 5] Sat Sep 14 18:03:04 2002 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
OID  restriction_I_property(property *v9268,list *v5252,ClaireBoolean *v3723)
{ { int  v5249 = 1;
    int  v6813 = v5252->length;
    { OID gc_local;
      while ((v5249 <= v6813))
      { // HOHO, GC_LOOP not needed !
        ((*(v5252))[v5249]=_oid_(ptype_type(OBJECT(ClaireType,(*(v5252))[v5249]))));
        ++v5249;
        } 
      } 
    } 
  return (restriction_I_list(v9268->definition,v5252,v3723));} 

OID  restriction_I_list(list *v15470,list *v5252,ClaireBoolean *v3723)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ OID Result = 0;
    { ClaireBoolean * v6669 = ((class_I_type(OBJECT(ClaireType,(*(v5252))[1]))->open == 3) ? CTRUE : CFALSE);
      OID  v9909 = _oid_(Kernel.emptySet);
      { OID gc_local;
        ITERATE(v5258);
        for (START(v15470); NEXT(v5258);)
        { GC_LOOP;
          if ((boolean_I_any(v9909) != CTRUE) && 
              (tmatch_ask_list(v5252,OBJECT(restriction,v5258)->domain) == CTRUE))
           { if (v3723 == CTRUE)
             GC__OID(v9909 = v5258, 1);
            else v9909= _oid_(OBJECT(restriction,v5258)->range);
              { ;break;} 
            } 
          else if (length_bag(_exp_list(OBJECT(restriction,v5258)->domain,v5252)) != 0)
           { if (v3723 != CTRUE)
             { GC__OID(v9909 = _oid_(U_type(OBJECT(ClaireType,v9909),OBJECT(restriction,v5258)->range)), 1);
              } 
            else if ((Optimize.compiler->safety <= 3) || 
                ((equal(v9909,_oid_(Kernel.emptySet)) != CTRUE) || 
                  (v6669 == CTRUE)))
             { v9909= _oid_(Optimize.ambiguous);
              { ;break;} 
              } 
            else GC__OID(v9909 = v5258, 1);
              } 
          GC_UNLOOP;} 
        } 
      Result = v9909;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  restriction_I_class(ClaireClass *v5243,list *v15470,list *v5252)
{ if (Optimize.compiler->safety > 3)
   ((*(v5252))[1]=_oid_(_exp_type(v5243,OBJECT(ClaireType,(*(v5252))[1]))));
  { OID Result = 0;
    { ITERATE(v5258);
      Result= _oid_(CFALSE);
      for (START(v15470); NEXT(v5258);)
      if (_inf_equalt_class(v5243,OBJECT(ClaireType,(*(OBJECT(restriction,v5258)->domain))[1])) == CTRUE)
       { if (tmatch_ask_list(v5252,OBJECT(restriction,v5258)->domain) == CTRUE)
         { Result = v5258;
          break;} 
        else if (length_bag(_exp_list(OBJECT(restriction,v5258)->domain,v5252)) != 0)
         { Result = _oid_(Optimize.ambiguous);
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireType * use_range_method(method *v9268,list *v13263)
{ if ((v9268->inline_ask == CTRUE) && 
      (v9268->typing == CNULL)) 
  { { ClaireType *Result ;
      { list * v15474 = GC_OBJECT(list,v9268->formula->vars);
        ClaireType * v13271 = Kernel._any;
        list * v1603;
        { { bag *v_list; OID v_val;
            OID v5263,CLcount;
            v_list = v15474;
             v1603 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5263 = (*(v_list))[CLcount];
              v_val = (*Kernel.range)(v5263);
              
              (*((list *) v1603))[CLcount] = v_val;} 
            } 
          GC_OBJECT(list,v1603);} 
        { OID gc_local;
          ITERATE(v5263);
          for (START(v15474); NEXT(v5263);)
          { GC_LOOP;
            put_property2(Kernel.range,OBJECT(ClaireObject,v5263),(*(v13263))[(((*Kernel.index)(v5263))+1)]);
            GC_UNLOOP;} 
          } 
        v13271= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v9268->formula->body))));
        { OID gc_local;
          ITERATE(v5263);
          for (START(v15474); NEXT(v5263);)
          { GC_LOOP;
            put_property2(Kernel.range,OBJECT(ClaireObject,v5263),(*(v1603))[(((*Kernel.index)(v5263))+1)]);
            GC_UNLOOP;} 
          } 
        if (INHERIT(v9268->range->isa,Kernel._type))
         v13271= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v13271),
          _oid_(v9268->range))));
        if (boolean_I_any(_oid_(v13271)) != CTRUE)
         (*Optimize.Cerror)(_string_("[207] inline ~S: range ~S is incompatible with ~S (inferred)"),
          _oid_(v9268),
          _oid_(v9268->range),
          GC_OID((*Optimize.c_type)(GC_OID(v9268->formula->body))));
        Result = v13271;
        } 
      return (Result);} 
     } 
  else{ GC_BIND;
    ;{ ClaireType *Result ;
      { OID  v5246 = GC_OID(v9268->typing);
        list * v1603;
        { { bag *v_list; OID v_val;
            OID v5261,CLcount;
            v_list = v13263;
             v1603 = v_list->clone(Kernel._type);
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5261 = (*(v_list))[CLcount];
              v_val = _oid_(ptype_type(OBJECT(ClaireType,v5261)));
              
              (*((list *) v1603))[CLcount] = v_val;} 
            } 
          GC_OBJECT(list,v1603);} 
        ClaireType * v1850 = v9268->range;
        ClaireType * v1851;
        { { ClaireObject *V_CC ;
            { ClaireHandler c_handle = ClaireHandler();
              if ERROR_IN 
              { if (INHERIT(OWNER(v5246),Core._lambda))
                 V_CC = OBJECT(ClaireType,apply_lambda(OBJECT(lambda,v5246),v1603));
                else if (INHERIT(OWNER(v5246),Kernel._property))
                 V_CC = OBJECT(ClaireType,apply_property(OBJECT(property,v5246),v1603));
                else if (INHERIT(OWNER(v5246),Kernel._function))
                 { OID v15730;{ list * v14719;
                    { list * v3279 = list::empty(Kernel.emptySet);
                      { int  v5254 = 1;
                        int  v6814 = (v13263->length+1);
                        { OID gc_local;
                          while ((v5254 <= v6814))
                          { // HOHO, GC_LOOP not needed !
                            v3279->addFast(_oid_(Kernel._object));
                            ++v5254;
                            } 
                          } 
                        } 
                      v14719 = GC_OBJECT(list,v3279);
                      } 
                    v15730 = apply_function(OBJECT(ClaireFunction,v5246),v14719,v1603);
                    } 
                  
                  V_CC=OBJECT(ClaireType,v15730);} 
                else V_CC = v1850;
                  ClEnv->cHandle--;} 
              else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
              { c_handle.catchIt();{ tformat_string("~S's 2nd-order type failed on ~S \n",0,list::alloc(2,_oid_(v9268),_oid_(v13263)));
                  V_CC = v1850;
                  } 
                } 
              else PREVIOUS_HANDLER;} 
            v1851= (ClaireType *) V_CC;} 
          GC_OBJECT(ClaireType,v1851);} 
        if ((boolean_I_any(sort_equal_class(osort_any(_oid_(v1850)),osort_any(_oid_(v1851)))) == CTRUE) || 
            (v9268->selector == Core.externC))
         Result = v1851;
        else if (boolean_I_any(sort_equal_class(Kernel._any,osort_any(_oid_(v1850)))) == CTRUE)
         { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v2072->t1 = Kernel._any);
          (v2072->t2 = v1851);
          Result = v2072;
          } 
        else Result = v1850;
          } 
      GC_UNBIND; return (Result);} 
    } 
  } 

ClaireType * c_type_Call_Optimize(Call *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (v9268->selector == Language.function_I)
       V_CC = Kernel._function;
      else { property * v5259 = v9268->selector;
          list * v5252 = GC_OBJECT(list,v9268->args);
          list * v15607;
          { { bag *v_list; OID v_val;
              OID v5264,CLcount;
              v_list = v5252;
               v15607 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5264 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v5264);
                
                (*((list *) v15607))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v15607);} 
          if (v5259 == Optimize.safe)
           V_CC = OBJECT(ClaireType,(*(v15607))[1]);
          else if ((v5259 == Core.externC) && 
              ((v5252->length == 2) && 
                (INHERIT(OWNER((*(v5252))[2]),Kernel._class))))
           V_CC = OBJECT(ClaireClass,(*(v5252))[2]);
          else if ((v5259 == Core.NEW) && 
              (INHERIT(OWNER((*(v5252))[1]),Kernel._class)))
           V_CC = OBJECT(ClaireClass,(*(v5252))[1]);
          else if (v5259 == Core.check_in)
           { V_CC = ((v5252->length == 2) ?
              sort_abstract_I_type(OBJECT(ClaireType,(*(v5252))[2])) :
              OBJECT(ClaireType,(*(v5252))[2]) );
            } 
          else if ((v5259 == Kernel.nth) && 
              (_inf_equal_type(OBJECT(ClaireType,(*(v15607))[1]),Kernel._array) == CTRUE))
           { if (_inf_equal_type(GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,(*(v15607))[1]))),Kernel._float) == CTRUE)
             V_CC = Kernel._float;
            else V_CC = member_type(OBJECT(ClaireType,(*(v15607))[1]));
              } 
          else if ((v5259 == Core._at) && 
              (INHERIT(OWNER((*(v5252))[1]),Kernel._property)))
           { property * v5256 = OBJECT(property,(*(v5252))[1]);
            OID  v5243 = (*(v5252))[2];
            if ((INHERIT(OWNER(v5243),Kernel._class)) && 
                (Kernel._method == owner_any((*Core._at)(_oid_(v5256),
                  v5243))))
             V_CC = set::alloc(1,GC_OID((*Core._at)(_oid_(v5256),
              v5243)));
            else V_CC = Kernel._any;
              } 
          else if ((v5259 == Kernel.get) && 
              (INHERIT(OWNER((*(v5252))[1]),Kernel._relation)))
           { ClaireRelation * v5258 = OBJECT(ClaireRelation,(*(v5252))[1]);
            if (INHERIT(v5258->isa,Kernel._property))
             { ClaireObject * v15843 = GC_OBJECT(ClaireObject,_at_property1(((property *) v5258),class_I_type(OBJECT(ClaireType,(*(v15607))[2]))));
              if (Kernel._slot == v15843->isa)
               { if ((_inf_equal_type(CLREAD(restriction,v15843,range),Kernel._bag) == CTRUE) && 
                    (Optimize.compiler->safety < 3))
                 V_CC = class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)((*(v5252))[2]))));
                else V_CC = ((belong_to(CLREAD(slot,v15843,DEFAULT),_oid_(CLREAD(restriction,v15843,range))) == CTRUE) ?
                  CLREAD(restriction,v15843,range) :
                  extends_type(CLREAD(restriction,v15843,range)) );
                } 
              else V_CC = v5258->range;
                } 
            else if (INHERIT(v5258->isa,Kernel._table))
             { V_CC = ((belong_to(CLREAD(table,v5258,DEFAULT),_oid_(v5258->range)) == CTRUE) ?
                v5258->range :
                extends_type(v5258->range) );
              } 
            else V_CC = CFALSE;
              } 
          else { OID  v5258 = GC_OID(restriction_I_property(v5259,v15607,CTRUE));
              if (Kernel._slot == OWNER(v5258))
               { if ((v5259 == Kernel.instances) && 
                    (INHERIT(OWNER((*(v5252))[1]),Kernel._class)))
                 { Param * v2072 = ((Param *) GC_OBJECT(Param,new_object_class(Core._Param)));
                  (v2072->arg = Kernel._list);
                  (v2072->params = list::alloc(1,_oid_(Kernel.of)));
                  (v2072->args = list::alloc(1,_oid_(set::alloc(1,(*(v5252))[1]))));
                  V_CC = v2072;
                  } 
                else V_CC = OBJECT(restriction,v5258)->range;
                  } 
              else if (Kernel._method == OWNER(v5258))
               V_CC = use_range_method(OBJECT(method,v5258),v15607);
              else if (boolean_I_any(_oid_(v5259->restrictions)) != CTRUE)
               V_CC = selector_psort_Call(v9268);
              else V_CC = (((v5259->open == 3) || 
                  (v5258 != _oid_(Optimize.ambiguous))) ?
                sort_abstract_I_type(v5259->range) :
                sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,restriction_I_property(v5259,v15607,CFALSE)))) );
              } 
            } 
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_Optimize(Call *v9268)
{ return (c_code_call_Call(v9268,Kernel._void));} 

OID  c_code_call_Call(Call *v9268,ClaireClass *v15693)
{ GC_BIND;
  ;{ OID Result = 0;
    { property * v5259 = v9268->selector;
      list * v5252 = GC_OBJECT(list,v9268->args);
      if ((INHERIT(OWNER((*(v5252))[1]),Core._global_variable)) && 
          ((equal((*Kernel.range)((*(v5252))[1]),_oid_(Kernel.emptySet)) == CTRUE) && 
            (designated_ask_any(GC_OID((*Kernel.value)((*(v5252))[1]))) == CTRUE)))
       ((*(v5252))[1]=(*Kernel.value)((*(v5252))[1]));
      { OID  v5253 = GC_OID(inline_optimize_ask_Call(v9268));
        ClaireBoolean * v5242 = inherit_ask_class(OWNER((*(v5252))[1]),Kernel._property);
        OID  v5244 = GC_OID(daccess_any(_oid_(v9268),_sup_integer(Optimize.compiler->safety,5)));
        if ((v5242 == CTRUE) && 
            (((v5259 == Kernel.put) || 
                (v5259 == Core.write)) && 
              (v5252->length == 3)))
         Result = c_code_write_Call(v9268);
        else if ((v5242 == CTRUE) && 
            ((v5259 == Core.put_store) && 
              ((v5252->length == 4) && 
                ((*(v5252))[4] == Kernel.ctrue))))
         Result = c_code_write_Call(v9268);
        else if ((v5242 == CTRUE) && 
            (v5259 == Core.unknown_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v5252))[1]),(*(v5252))[2],CNULL,CTRUE);
        else if ((v5242 == CTRUE) && 
            (v5259 == Core.known_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v5252))[1]),(*(v5252))[2],CNULL,CFALSE);
        else if ((v5242 == CTRUE) && 
            ((v5259 == Core.erase) && 
              (INHERIT(OWNER((*(v5252))[2]),Language._Variable))))
         Result = (*Optimize.c_code)(GC_OID(Produce_erase_property2(OBJECT(property,(*(v5252))[1]),OBJECT(Variable,(*(v5252))[2]))),
          _oid_(v15693));
        else if (v5259 == Optimize.safe)
         { int  v5265 = Optimize.compiler->safety;
          ClaireBoolean * v5242 = Optimize.compiler->overflow_ask;
          OID  v5264 = CNULL;
          (Optimize.compiler->safety = 1);
          (Optimize.compiler->overflow_ask = CTRUE);
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Optimize.safe);
              (v2072->args = list::alloc(1,GC_OID((*Optimize.c_code)((*(v5252))[1],
                _oid_(v15693)))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v5264 = _oid_(v2072);
              } 
            GC_OID(v5264);} 
          (Optimize.compiler->safety = v5265);
          (Optimize.compiler->overflow_ask = v5242);
          Result = v5264;
          } 
        else if (((v5259 == Kernel.add) || 
              (v5259 == Kernel.add_I)) && 
            (v5242 == CTRUE))
         Result = c_code_add_Call(v9268);
        else if (((v5259 == Kernel.add) || 
              (v5259 == Kernel.add_I)) && 
            (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v5252))[1]))),Kernel._bag) == CTRUE))
         Result = c_code_add_bag_Call(v9268);
        else if ((v5242 == CTRUE) && 
            (v5259 == Kernel._delete))
         Result = c_code_delete_Call(v9268);
        else if ((contain_ask_set(Optimize.OPT->to_remove,_oid_(v5259)) == CTRUE) || 
            ((v5259 == Optimize.c_interface) && 
                ((v5252->length == 2) && 
                  (contain_ask_set(GC_OBJECT(set,Optimize.OPT->legal_modules),GC_OID(get_module_object(v5259))) != CTRUE))))
         Result = Core.nil->value;
        else if (v5244 != CNULL)
         Result = v5244;
        else if (Kernel._method == OWNER(v5253))
         Result = c_inline_method1(OBJECT(method,v5253),v5252,c_srange_method(OBJECT(method,v5253)));
        else if (((v5259 == Kernel._equal) || 
              (v5259 == Core._I_equal)) && 
            (daccess_any((*(v5252))[1],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v5252))[1]))))[1]),(*(OBJECT(bag,(*Core.args)((*(v5252))[1]))))[2],(*(v5252))[2],equal(_oid_(v5259),_oid_(Kernel._equal)));
        else if (((v5259 == Kernel._equal) || 
              (v5259 == Core._I_equal)) && 
            (daccess_any((*(v5252))[2],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v5252))[2]))))[1]),(*(OBJECT(bag,(*Core.args)((*(v5252))[2]))))[2],(*(v5252))[1],equal(_oid_(v5259),_oid_(Kernel._equal)));
        else if (((v5259 == Kernel.nth_equal) || 
              (v5259 == Kernel.put)) && 
            ((INHERIT(OWNER((*(v5252))[1]),Kernel._table)) && 
              (v5252->length == 3)))
         Result = c_code_table_Call(v9268);
        else if (((v5259 == Kernel.nth_put) || 
              (v5259 == Kernel.nth_equal)) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v5252))[1]))),Kernel._array) == CTRUE) && 
              (v5252->length == 3)))
         Result = c_code_array_Call(v9268);
        else if ((v5259 == Kernel.nth) || 
            (((v5259 == Kernel.get) && 
                (INHERIT(OWNER((*(v5252))[1]),Kernel._table))) || 
              ((v5259 == Kernel.nth_get) && 
                  (Kernel._array == OWNER((*(v5252))[1])))))
         Result = c_code_nth_Call(v9268);
        else if (v5259 == Kernel._Z)
         Result = c_code_belong_Call(v9268);
        else if (v5259 == Core.Id)
         Result = (*Optimize.c_code)(GC_OID(OPT_EVAL((*(v5252))[1])));
        else if (v5259 == Language.function_I)
         Result = _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(v5252))[1]))));
        else if ((v5259 == Core.NOT) && 
            (INHERIT(OWNER((*(v5252))[1]),Language._Select)))
         Result = c_code_not_Select(OBJECT(Select,(*(v5252))[1]));
        else if ((v5259 == Core.call) && 
            (INHERIT(OWNER((*(v5252))[1]),Kernel._property)))
         { OID  v15680;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            update_property(Kernel.selector,
              v2072,
              2,
              Kernel._object,
              (*(v5252))[1]);
            (v2072->args = cdr_list(v5252));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v15680 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v15680);
          } 
        else if (v5259->open == 3)
         { list * v257;
          { { bag *v_list; OID v_val;
              OID v5264,CLcount;
              v_list = v5252;
               v257 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5264 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v5264);
                
                (*((list *) v257))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v257);} 
          Result = c_warn_property(v5259,v5252,v257);
          } 
        else { ClaireBoolean * g0080I;
          { ClaireBoolean *v_and;
            { v_and = ((v5259 == Language.bit_vector) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0080I =CFALSE; 
              else { { OID  v5976;
                  { OID gc_local;
                    ITERATE(v5265);
                    v5976= _oid_(CFALSE);
                    bag *v5265_support;
                    v5265_support = GC_OBJECT(list,v9268->args);
                    for (START(v5265_support); NEXT(v5265);)
                    { GC_LOOP;
                      if (!INHERIT(OWNER(v5265),Kernel._integer))
                       { v5976 = Kernel.ctrue;
                        break;} 
                      GC_UNLOOP;} 
                    } 
                  v_and = not_any(v5976);
                  } 
                if (v_and == CFALSE) g0080I =CFALSE; 
                else g0080I = CTRUE;} 
              } 
            } 
          
          if (g0080I == CTRUE) Result = OPT_EVAL(_oid_(v9268));
            else if ((v5259 == Optimize.anyObject_I) || 
              ((v5259 == Optimize.object_I) || 
                ((v5259 == Kernel.add_method) && 
                    (v5242 == CTRUE))))
           Result = _oid_(v9268);
          else { list * v15607;
              { { bag *v_list; OID v_val;
                  OID v5264,CLcount;
                  v_list = v5252;
                   v15607 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v5264 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_type)(v5264);
                    
                    (*((list *) v15607))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v15607);} 
              OID  v5266 = GC_OID(restriction_I_property(v5259,v15607,CTRUE));
              if (Kernel._slot == OWNER(v5266))
               { ClaireBoolean * v2413 = ((belong_to(OBJECT(slot,v5266)->DEFAULT,_oid_(OBJECT(restriction,v5266)->range)) != CTRUE) ? ((contain_ask_set(Optimize.OPT->knowns,_oid_(v5259)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE): CFALSE);
                if ((v2413 != CTRUE) || 
                    (designated_ask_any((*(v5252))[1]) == CTRUE))
                 { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                  (v2072->selector = OBJECT(slot,v5266));
                  (v2072->arg = (*Optimize.c_code)((*(v5252))[1],
                    _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v5266)))))));
                  (v2072->test = v2413);
                  add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                  Result = _oid_(v2072);
                  } 
                else { Result = c_warn_property(v5259,v5252,v15607);
                    } 
                  } 
              else if (Kernel._method == OWNER(v5266))
               { if (v5259 == Kernel.nth_equal)
                 (Optimize.OPT->use_nth_equal = CTRUE);
                if (((v5259 == Kernel.begin) || 
                      (v5259 == Kernel.end)) && 
                    (INHERIT(OWNER((*(v5252))[1]),Kernel._module)))
                 OPT_EVAL(_oid_(v9268));
                if ((last_list(OBJECT(restriction,v5266)->domain) == _oid_(Kernel._listargs)) || 
                    (((*(OBJECT(restriction,v5266)->domain))[1] == _oid_(Kernel._void)) && 
                        ((*(v5252))[1] != _oid_(ClEnv))))
                 Result = _oid_(open_message_property(v5259,v5252));
                else Result = c_code_method_method2(OBJECT(method,v5266),v5252,v15607,v15693);
                  } 
              else if (INHERIT(OWNER(v5266),Kernel._keyword))
               Result = c_warn_property(v5259,v5252,v15607);
              else Result = c_warn_Call(v9268,_oid_(v15607));
                } 
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

Call * open_message_property(property *v9268,list *v5252)
{ GC_BIND;
  selector_register_property(v9268);
  { Call *Result ;
    { list * v8441;
      { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = v5252;
           v8441 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            if ((*Optimize.c_type)(v5264) != _oid_(Kernel._void))
             v_val = (*Optimize.c_code)(v5264,
              _oid_(Kernel._any));
            else v_val = (*Optimize.Cerror)(_string_("[206] use of void ~S in ~S~S"),
                v5264,
                _oid_(v9268),
                _oid_(v5252));
              
            (*((list *) v8441))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v8441);} 
      if (Optimize.OPT->allocation == CTRUE)
       { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = v8441;
           v8441 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v5264);
            
            (*((list *) v8441))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v8441);} 
      { ClaireBoolean * g0082I;
        { ClaireBoolean *v_and;
          { v_and = Optimize.compiler->diet_ask;
            if (v_and == CFALSE) g0082I =CFALSE; 
            else { { OID  v7898;
                { ITERATE(v5264);
                  v7898= _oid_(CFALSE);
                  for (START(v5252); NEXT(v5264);)
                  if ((INHERIT(OWNER(v5264),Kernel._class)) || 
                      (INHERIT(OWNER(v5264),Kernel._property)))
                   { v7898 = Kernel.ctrue;
                    break;} 
                  } 
                v_and = boolean_I_any(v7898);
                } 
              if (v_and == CFALSE) g0082I =CFALSE; 
              else g0082I = CTRUE;} 
            } 
          } 
        
        if (g0082I == CTRUE) { warn_void();
            tformat_string("Non diet call ~S(~A)\n",2,list::alloc(2,_oid_(v9268),_oid_(v5252)));
            } 
          } 
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = v9268);
        (v2072->args = v8441);
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        Result = v2072;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call(Call *v9268)
{ return (((v9268->selector == Language.function_I) ? CTRUE : (((v9268->selector == Optimize.safe) ? ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)((*(v9268->args))[1]))) == CTRUE) : ((stable_ask_relation(v9268->selector) != CTRUE) || 
      ((OBJECT(ClaireBoolean,_oid_((INHERIT(v9268->selector->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v9268->selector->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v9268->selector->range))))))) != CTRUE))) ? CTRUE : CFALSE)));} 

OID  daccess_any(OID v9268,ClaireBoolean *v5242)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v9268),Language._Call))
     { list * v5252 = GC_OBJECT(list,OBJECT(Call,v9268)->args);
      ClaireObject * v15843;
      { if ((OBJECT(Call,v9268)->selector == Kernel.get) && 
            (INHERIT(OWNER((*(v5252))[1]),Kernel._property)))
         v15843 = _at_property1(OBJECT(property,(*(v5252))[1]),class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v5252))[2])))));
        else v15843 = CFALSE;
          GC_OBJECT(ClaireObject,v15843);} 
      if ((Kernel._slot == v15843->isa) && ((v5242 == CTRUE) || 
          ((belong_to(CLREAD(slot,v15843,DEFAULT),_oid_(CLREAD(restriction,v15843,range))) == CTRUE) || 
            ((CLREAD(slot,v15843,srange) == Kernel._any) || 
              (CLREAD(slot,v15843,srange) == Kernel._integer)))))
       { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = ((slot *) v15843));
        (v2072->arg = (*Optimize.c_code)((*(v5252))[2],
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v15843)))))));
        (v2072->test = CFALSE);
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else Result = CNULL;
        } 
    else Result = CNULL;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call_slot(Call_slot *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { slot * v5259 = v9268->selector;
      OID  v5264 = v9268->arg;
      Result = ((not_any(_oid_((INHERIT(v5259->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v5259->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v5259->range)))))) == CTRUE) ? ((v5259->range != Kernel._float) ? (((1 <= v5259->selector->open) || 
          (gcsafe_ask_class(domain_I_restriction(v5259)) != CTRUE)) ? CTRUE: CFALSE): CFALSE): CFALSE);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_slot_Optimize(Call_slot *v9268)
{ return (v9268->selector->range);} 

ClaireType * c_type_Call_table_Optimize(Call_table *v9268)
{ return (v9268->selector->range);} 

ClaireType * c_type_Call_array_Optimize(Call_array *v9268)
{ return (OBJECT(ClaireType,v9268->test));} 

OID  c_code_write_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5256 = (*(v9268->args))[1];
      OID  v5264 = (*(v9268->args))[2];
      OID  v5265 = (*(v9268->args))[3];
      OID  v15875 = GC_OID((*Optimize.c_type)(v5265));
      property * v15688 = v9268->selector;
      OID  v5259 = GC_OID((*Optimize.restriction_I)(v5256,
        _oid_(list::alloc(1,GC_OID((*Optimize.c_type)(v5264)))),
        Kernel.ctrue));
      (Optimize.OPT->use_update = CTRUE);
      if (contain_ask_set(Optimize.OPT->to_remove,v5256) == CTRUE)
       Result = Core.nil->value;
      else if ((Kernel._slot == OWNER(v5259)) && ((_inf_equal_type(OBJECT(ClaireType,v15875),OBJECT(restriction,v5259)->range) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if ((v5265 != CNULL) && 
            (boolean_I_any((*Kernel._exp)(v15875,
              GC_OID((*Kernel.srange)(v5259)))) != CTRUE))
         { warn_void();
          tformat_string("sort error in ~S: ~S is a ~S\n",2,list::alloc(3,_oid_(v9268),
            v5265,
            v15875));
          } 
        if (((_inf_equal_type(OBJECT(ClaireType,v15875),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v5259)))) == CTRUE) || 
              ((_inf_equal_type(OBJECT(ClaireType,v15875),Kernel._object) == CTRUE) || 
                (((*Kernel.srange)(v5259) != _oid_(Kernel._object)) || 
                  (v5265 == CNULL)))) && 
            ((v15688 != Core.write) || 
                (Update_ask_relation(OBJECT(ClaireRelation,v5256),v5264,v5265) == CTRUE)))
         { OID  v13275 = GC_OID((*Optimize.c_code)(v5264,
            _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v5259)))))));
          OID  v13276 = GC_OID(c_strict_code_any(v5265,psort_any(GC_OID((*Kernel.range)(v5259)))));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = v5256);
          (v2072->value = v13276);
          { Update * v6843; 
            OID  v6844;
            v6843 = v2072;
            if (v15688 != Core.write)
             v6844 = _oid_(v15688);
            else v6844 = (*Optimize.c_code)(v5264,
                _oid_(Kernel._any));
              (v6843->arg = v6844);} 
          { Update * v6845; 
            OID  v6846;
            v6845 = v2072;
            { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              update_property(Kernel.selector,
                v2072,
                2,
                Kernel._object,
                v5259);
              (v2072->arg = v13275);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
              v6846 = _oid_(v2072);
              } 
            (v6845->var = v6846);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if (v15688 == Kernel.put)
         { OID  v12703;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.store);
            (v2072->args = list::alloc(5,v5264,
              (*Kernel.index)(v5259),
              GC_OID((*Kernel.srange)(v5259)),
              v5265,
              GC_OID((*Kernel.store_ask)(v5256))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v12703 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v12703);
          } 
        else { if (Optimize.compiler->diet_ask == CTRUE)
             { warn_void();
              tformat_string("~S is not a diet call",2,list::alloc(1,_oid_(v9268)));
              } 
            { OID  v13664;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.update);
                (v2072->args = list::alloc(5,v5256,
                  v5264,
                  (*Kernel.index)(v5259),
                  GC_OID((*Kernel.srange)(v5259)),
                  v5265));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v13664 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v13664);
              } 
            } 
          } 
      else { list * v15607;
          { { bag *v_list; OID v_val;
              OID v5264,CLcount;
              v_list = GC_OBJECT(list,v9268->args);
               v15607 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5264 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v5264);
                
                (*((list *) v15607))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v15607);} 
          OID  v5266 = GC_OID(restriction_I_property(v15688,v15607,CTRUE));
          if (Kernel._method == OWNER(v5266))
           Result = c_code_method_method1(OBJECT(method,v5266),GC_OBJECT(list,v9268->args),v15607);
          else Result = c_warn_Call(v9268,_oid_(v15607));
            } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_hold_property(property *v5256,OID v5264,OID v5265,ClaireBoolean *v5242)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5259 = GC_OID(restriction_I_property(v5256,list::alloc(1,GC_OID((*Optimize.c_type)(v5264))),CTRUE));
      if ((Kernel._slot == OWNER(v5259)) && ((v5265 == CNULL) || 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5265))),OBJECT(slot,v5259)->srange) == CTRUE) && 
              (identifiable_ask_any(v5265) == CTRUE))))
       { Call_slot * v15192;
        { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
            update_property(Kernel.selector,
              v2072,
              2,
              Kernel._object,
              v5259);
            (v2072->arg = (*Optimize.c_code)(v5264,
              _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v5259)))))));
            (v2072->test = CFALSE);
            add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
            v15192 = v2072;
            } 
          GC_OBJECT(Call_slot,v15192);} 
        Call_method2 * v15186;
        { { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v2072->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
            (v2072->args = list::alloc(2,_oid_(v15192),GC_OID((*Optimize.c_code)(v5265,
              GC_OID((*Kernel.srange)(v5259))))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
            v15186 = v2072;
            } 
          GC_OBJECT(Call_method2,v15186);} 
        if (v5242 == CTRUE)
         Result = (*Optimize.c_code)(_oid_(v15186));
        else { OID  v2038;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.NOT);
              (v2072->args = list::alloc(1,_oid_(v15186)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v2038 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v2038);
            } 
          } 
      else { list * v5252 = list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any));
          { list * v2999;
            { OID v_bag;
              GC_ANY(v2999= list::empty(Kernel.emptySet));
              { { OID  v3960;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.get);
                    (v2072->args = list::alloc(2,_oid_(v5256),v5264));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v3960 = _oid_(v2072);
                    } 
                  v_bag = (*Optimize.c_code)(v3960,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v2999)->addFast(v_bag);
              ((list *) v2999)->addFast(GC_OID((*Optimize.c_code)(v5265,
                _oid_(Kernel._any))));} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(((v5242 == CTRUE) ?
              Kernel._equal :
              Core._I_equal ),v5252))),v2999,v5252);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { property * v5256 = OBJECT(property,(*(v9268->args))[1]);
      OID  v5264 = (*(v9268->args))[2];
      OID  v5265 = (*(v9268->args))[3];
      ClaireObject * v5259 = GC_OBJECT(ClaireObject,_at_property1(v5256,class_I_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v5264)))))));
      (Optimize.OPT->use_update = CTRUE);
      if ((Kernel._slot == v5259->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5265))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v5259,range)))) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if (Update_ask_relation2(v5256,v9268->selector) == CTRUE)
         { OID  v15778 = GC_OID((*Optimize.c_code)(v5264,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v5259)))))));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = _oid_(v5256));
          (v2072->arg = _oid_(Kernel.add));
          { Update * v6874; 
            OID  v6878;
            v6874 = v2072;
            { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              (v2072->selector = ((slot *) v5259));
              (v2072->arg = v15778);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
              v6878 = _oid_(v2072);
              } 
            (v6874->var = v6878);} 
          (v2072->value = (*Optimize.c_code)(v5265,
            _oid_(psort_any(GC_OID(_oid_(member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v5259)))))))))));
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if ((designated_ask_any(v5264) == CTRUE) && 
            ((v5256->store_ask != CTRUE) && 
                ((v9268->selector == Kernel.add_I) || 
                    (v5256->inverse == (NULL)))))
         { OID  v15778 = GC_OID((*Optimize.c_code)(v5264,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v5259)))))));
          { OID  v6849;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.add);
              { Call * v6881; 
                list * v6882;
                v6881 = v2072;
                { OID v_bag;
                  GC_ANY(v6882= list::empty(Kernel.emptySet));
                  { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                      (v2072->selector = ((slot *) v5259));
                      (v2072->arg = v15778);
                      (v2072->test = CFALSE);
                      add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v6882)->addFast(v_bag);
                  ((list *) v6882)->addFast(v5265);} 
                (v6881->args = v6882);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v6849 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v6849);
            } 
          } 
        else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add_I,Kernel._property))),list::alloc(4,_oid_(v5256),
            v5264,
            (*Kernel.index)(_oid_(v5259)),
            v5265),list::alloc(4,_oid_(Kernel._property),
            GC_OID((*Optimize.c_type)(v5264)),
            _oid_(Kernel._integer),
            GC_OID((*Optimize.c_type)(v5265))));
          } 
      else { list * v9726;
          { { bag *v_list; OID v_val;
              OID v5264,CLcount;
              v_list = GC_OBJECT(list,v9268->args);
               v9726 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5264 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v5264);
                
                (*((list *) v9726))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v9726);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add,Kernel._property))),GC_OBJECT(list,v9268->args),v9726);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_bag_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v1850 = GC_OID((*Optimize.c_type)((*(v9268->args))[1]));
      OID  v1851 = GC_OID((*Optimize.c_type)((*(v9268->args))[2]));
      property * v13267;
      if (((INHERIT(OBJECT(ClaireObject,v1850)->isa,Core._Param)) && 
            (_inf_equal_type(OBJECT(ClaireType,v1851),GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v1850)))) == CTRUE)) || 
          (4 <= Optimize.compiler->safety))
       v13267 = Kernel.add_I;
      else v13267 = v9268->selector;
        list * v905 = list::alloc(2,v1850,v1851);
      OID  v5266 = GC_OID(restriction_I_property(v13267,v905,CTRUE));
      if (Kernel._method == OWNER(v5266))
       Result = c_code_method_method1(OBJECT(method,v5266),GC_OBJECT(list,v9268->args),v905);
      else Result = c_warn_Call(v9268,_oid_(v905));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_delete_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5256 = (*(v9268->args))[1];
      OID  v5264 = (*(v9268->args))[2];
      OID  v5265 = (*(v9268->args))[3];
      ClaireObject * v5259 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v5256),class_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5264))))));
      (Optimize.OPT->use_update = CTRUE);
      if ((OBJECT(ClaireRelation,v5256)->inverse == (NULL)) && 
          ((designated_ask_any(v5264) == CTRUE) && 
            ((Kernel._slot == v5259->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5265))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v5259,range)))) == CTRUE) || 
                (4 <= Optimize.compiler->safety)))))
       { OID  v15778 = GC_OID((*Optimize.c_code)(v5264,
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v5259)))))));
        { OID  v10687;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._delete);
            { Call * v7552; 
              list * v7554;
              v7552 = v2072;
              { OID v_bag;
                GC_ANY(v7554= list::empty(Kernel.emptySet));
                { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                    (v2072->selector = ((slot *) v5259));
                    (v2072->arg = v15778);
                    (v2072->test = CFALSE);
                    add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7554)->addFast(v_bag);
                ((list *) v7554)->addFast(v5265);} 
              (v7552->args = v7554);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v10687 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v10687);
          } 
        } 
      else { list * v4003;
          { { bag *v_list; OID v_val;
              OID v5264,CLcount;
              v_list = GC_OBJECT(list,v9268->args);
               v4003 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5264 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v5264);
                
                (*((list *) v4003))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v4003);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel._delete,Kernel._property))),GC_OBJECT(list,v9268->args),v4003);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_not_Select(Select *v5264)
{ GC_BIND;
  { OID Result = 0;
    { OID  v4963;
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = Core.NOT);
        { Call * v7557; 
          list * v7558;
          v7557 = v2072;
          { OID v_bag;
            GC_ANY(v7558= list::empty(Kernel.emptySet));
            { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                (v2072->var = v5264->var);
                (v2072->set_arg = v5264->set_arg);
                { Iteration * v7559; 
                  OID  v7560;
                  v7559 = v2072;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = v5264->arg);
                    { If * v7561; 
                      OID  v7562;
                      v7561 = v2072;
                      { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                        (v2072->arg = Kernel.ctrue);
                        add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                        v7562 = _oid_(v2072);
                        } 
                      (v7561->arg = v7562);} 
                    (v2072->other = CNULL);
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v7560 = _oid_(v2072);
                    } 
                  (v7559->arg = v7560);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              GC_OID(v_bag);} 
            ((list *) v7558)->addFast(v_bag);} 
          (v7557->args = v7558);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        v4963 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v4963);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_belong_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5264 = (*(v9268->args))[1];
      OID  v5265 = (*(v9268->args))[2];
      list * v15607 = list::alloc(2,GC_OID((*Optimize.c_type)(v5265)),GC_OID((*Optimize.c_type)(v5264)));
      if (Kernel._set == OWNER(v5265))
       { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
        { Or * v7583; 
          list * v7584;
          v7583 = v2072;
          { list * v9947 = list::empty(Kernel.emptySet);
            { OID gc_local;
              ITERATE(v5266);
              bag *v5266_support;
              v5266_support = GC_OBJECT(bag,enumerate_any(v5265));
              for (START(v5266_support); NEXT(v5266);)
              { GC_LOOP;
                { OID  v1025;
                  { { OID  v1986;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel._equal);
                        (v2072->args = list::alloc(2,v5264,v5266));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v1986 = _oid_(v2072);
                        } 
                      v1025 = (*Optimize.c_code)(v1986,
                        _oid_(Kernel._any));
                      } 
                    GC_OID(v1025);} 
                  v9947->addFast(v1025);
                  } 
                GC_UNLOOP;} 
              } 
            v7584 = GC_OBJECT(list,v9947);
            } 
          (v7583->args = v7584);} 
        add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if ((_inf_equal_type(OBJECT(ClaireType,(*(v15607))[1]),Kernel._list) == CTRUE) || 
          (_inf_equal_type(OBJECT(ClaireType,(*(v15607))[1]),Kernel._tuple) == CTRUE))
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,list::alloc(2,_oid_(Kernel._list),_oid_(Kernel._any))))),list::alloc(2,v5265,v5264),v15607);
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v15607))[1]),Kernel._set) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,list::alloc(2,_oid_(Kernel._set),_oid_(Kernel._any))))),list::alloc(2,v5265,v5264),v15607);
      else if (v5265 == _oid_(Kernel._object))
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class))))),list::alloc(2,v5264,v5265),list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class)));
      else Result = (*Optimize.member_code)(v5265,
          v5264);
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_nth_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { list * v5252 = GC_OBJECT(list,v9268->args);
      OID  v5264 = (*(v5252))[1];
      property * v5256 = v9268->selector;
      OID  v5260 = GC_OID((*Optimize.c_type)(v5264));
      ClaireType * v15503 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v5260)));
      OID  v5258;
      { { list * v2947;
          { { bag *v_list; OID v_val;
              OID v5261,CLcount;
              v_list = v5252;
               v2947 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5261 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v5261);
                
                (*((list *) v2947))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v2947);} 
          v5258 = restriction_I_property(v5256,v2947,CTRUE);
          } 
        GC_OID(v5258);} 
      if (contain_ask_set(Optimize.OPT->to_remove,v5264) == CTRUE)
       Result = Core.nil->value;
      else if (((INHERIT(OWNER(v5264),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v5264)->params),Kernel._integer))) && 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v5252))[2]))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v5264)))) == CTRUE) || 
              ((v5256 == Kernel.nth) && 
                  (Optimize.compiler->safety > 2))))
       { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v2072,
          2,
          Kernel._object,
          v5264);
        (v2072->arg = (*Optimize.c_code)((*(v5252))[2],
          _oid_(Kernel._integer)));
        (v2072->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v5264)),GC_OID((*Kernel.range)(v5264))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v5264) == 0) ? CTRUE : ((v5256 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (((INHERIT(OWNER(v5264),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v5264)->params),Kernel._list))) && 
          ((v5252->length == 3) && 
            ((_inf_equal_type(GC_OBJECT(tuple,tuple_I_list(list::alloc(2,GC_OID((*Optimize.c_type)((*(v5252))[2])),GC_OID((*Optimize.c_type)((*(v5252))[3]))))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v5264)))) == CTRUE) || 
                (Optimize.compiler->safety > 2))))
       { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v2072,
          2,
          Kernel._object,
          v5264);
        { Call_table * v7588; 
          OID  v7589;
          v7588 = v2072;
          { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)((*(v5252))[2],
              _oid_(Kernel._integer))),GC_OID((*Optimize.c_code)((*(v5252))[3],
              _oid_(Kernel._integer)))));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
            v7589 = _oid_(v2072);
            } 
          (v7588->arg = v7589);} 
        (v2072->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v5264)),GC_OID((*Kernel.range)(v5264))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v5264) == 0) ? CTRUE : ((v5256 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if ((_inf_equal_type(OBJECT(ClaireType,v5260),Kernel._array) == CTRUE) && 
          (((v5256 == Kernel.nth_get) || 
              (Optimize.compiler->safety > 2)) && 
            ((_inf_equal_type(v15503,Kernel._float) == CTRUE) || 
                (equal(_oid_(_exp_type(v15503,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE))))
       { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v2072->selector = (*Optimize.c_code)(v5264,
          _oid_(Kernel._array)));
        (v2072->arg = (*Optimize.c_code)((*(v5252))[2],
          _oid_(Kernel._integer)));
        (v2072->test = _oid_(v15503));
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (Kernel._method == OWNER(v5258))
       { list * v5830;
        { { bag *v_list; OID v_val;
            OID v5264,CLcount;
            v_list = GC_OBJECT(list,v9268->args);
             v5830 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v5264 = (*(v_list))[CLcount];
              v_val = (*Optimize.c_type)(v5264);
              
              (*((list *) v5830))[CLcount] = v_val;} 
            } 
          GC_OBJECT(list,v5830);} 
        Result = c_code_method_method1(OBJECT(method,v5258),GC_OBJECT(list,v9268->args),v5830);
        } 
      else { list * v6791;
          { { bag *v_list; OID v_val;
              OID v5264,CLcount;
              v_list = GC_OBJECT(list,v9268->args);
               v6791 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5264 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v5264);
                
                (*((list *) v6791))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v6791);} 
          Result = c_warn_property(v5256,GC_OBJECT(list,v9268->args),v6791);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_table_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { property * v15685 = v9268->selector;
      table * v5256 = OBJECT(table,(*(v9268->args))[1]);
      OID  v5264 = (*(v9268->args))[2];
      OID  v5265 = (*(v9268->args))[3];
      if (contain_ask_set(Optimize.OPT->to_remove,_oid_(v5256)) == CTRUE)
       Result = Core.nil->value;
      else if ((v15685 == Kernel.put) || 
          (((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5264))),v5256->domain) == CTRUE) || 
                (5 <= Optimize.compiler->safety)) && 
              ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5265))),v5256->range) == CTRUE) || 
                  (4 <= Optimize.compiler->safety))))
       { if ((Update_ask_relation(v5256,v5264,v5265) == CTRUE) && 
            ((INHERIT(OWNER(v5256->params),Kernel._list)) || 
                (INHERIT(OWNER(v5256->params),Kernel._integer))))
         { OID  v13275 = GC_OID((*Optimize.c_code)(v5264,
            _oid_(Kernel._any)));
          OID  v13276 = GC_OID((*Optimize.c_code)(v5265,
            _oid_(Kernel._any)));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = _oid_(v5256));
          (v2072->value = v13276);
          { Update * v7595; 
            OID  v7614;
            v7595 = v2072;
            if (v15685 == Kernel.put)
             v7614 = _oid_(Kernel.put);
            else v7614 = v13275;
              (v7595->arg = v7614);} 
          { Update * v7615; 
            OID  v7616;
            v7615 = v2072;
            { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
              (v2072->selector = v5256);
              (v2072->arg = v13275);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
              v7616 = _oid_(v2072);
              } 
            (v7615->var = v7616);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if ((v15685 == Kernel.put) || 
            ((v5256->inverse == (NULL)) && 
                (v5256->if_write == CNULL)))
         Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.put,Kernel._table))),GC_OBJECT(list,v9268->args),list::alloc(3,_oid_(Kernel._table),
          _oid_(Kernel._any),
          _oid_(Kernel._any)));
        else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_put,Kernel._table))),GC_OBJECT(list,v9268->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
      else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_equal,Kernel._table))),GC_OBJECT(list,v9268->args),list::alloc(3,_oid_(Kernel._table),
          _oid_(Kernel._any),
          _oid_(Kernel._any)));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_array_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { property * v15685 = v9268->selector;
      OID  v5256 = (*(v9268->args))[1];
      OID  v15717 = GC_OID((*Optimize.c_type)(v5256));
      ClaireType * v15503 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v15717)));
      OID  v5264 = (*(v9268->args))[2];
      OID  v5265 = (*(v9268->args))[3];
      ClaireBoolean * v12670 = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v5265))),GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v15717)))) == CTRUE) ? CTRUE : ((4 <= Optimize.compiler->safety) ? CTRUE : CFALSE));
      if (((v15685 == Kernel.nth_put) || 
            (v12670 == CTRUE)) && 
          ((_inf_equal_type(v15503,Kernel._float) == CTRUE) || 
              (equal(_oid_(_exp_type(v15503,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE)))
       { OID  v13275 = GC_OID((*Optimize.c_code)(v5264,
          _oid_(Kernel._integer)));
        OID  v13276;
        { { OID  v15393;
            if (_inf_equal_type(v15503,Kernel._float) == CTRUE)
             v15393 = _oid_(Kernel._float);
            else v15393 = _oid_(Kernel._any);
              v13276 = (*Optimize.c_code)(v5265,
              v15393);
            } 
          GC_OID(v13276);} 
        Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v2072->selector = v5256);
        (v2072->value = v13276);
        (v2072->arg = _oid_(Kernel.put));
        { Update * v7618; 
          OID  v7619;
          v7618 = v2072;
          { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
            (v2072->selector = (*Optimize.c_code)(v5256,
              _oid_(Kernel._array)));
            (v2072->arg = v13275);
            (v2072->test = _oid_(v15503));
            add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
            v7619 = _oid_(v2072);
            } 
          (v7618->var = v7619);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(((v12670 == CTRUE) ?
          Kernel.nth_put :
          v15685 ),Kernel._array))),GC_OBJECT(list,v9268->args),list::alloc(3,v15717,
          _oid_(Kernel._any),
          _oid_(Kernel._any)));
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation(ClaireRelation *v5256,OID v5264,OID v5265)
{ return (((v5256 != Kernel.inverse) ? ((((v5256->if_write != CNULL) && 
        (!INHERIT(OWNER(v5256->if_write),Kernel._list))) || 
      ((v5256->inverse == (NULL)) && 
          (((INHERIT(v5256->isa,Kernel._table)) ? (INHERIT(OWNER(CLREAD(table,v5256,params)),Kernel._integer)) : (CTRUE == CTRUE)) && 
            ((v5256->store_ask == CTRUE) ? ((designated_ask_any(v5264) == CTRUE) && 
                ((designated_ask_any(v5265) == CTRUE) && 
                  ((multi_ask_any(_oid_(v5256)) != CTRUE) && 
                    (identifiable_ask_any(v5265) == CTRUE)))) : (CTRUE == CTRUE))))) ? CTRUE: CFALSE): CFALSE));} 

ClaireBoolean * Update_ask_relation2(ClaireRelation *v5256,ClaireRelation *v5259)
{ return (((v5256->if_write != CNULL) ? ((!INHERIT(OWNER(v5256->if_write),Kernel._list)) ? ((v5259 == Kernel.add) ? CTRUE: CFALSE): CFALSE): CFALSE));} 

ClaireType * c_type_Update_Optimize(Update *v9268)
{ return (Kernel._void);} 

OID  c_code_method_method1(method *v9268,list *v5252,list *v15607)
{ return (c_code_method_method2(v9268,v5252,v15607,c_srange_method(v9268)));} 

OID  c_code_method_method2(method *v9268,list *v5252,list *v15607,ClaireClass *v15693)
{ if ((v9268->module_I != claire.it) || 
      ((Optimize.compiler->safety > 4) || 
        (v9268->functional != (NULL)))) 
  { { OID Result = 0;
      { list * v15456 = v9268->domain;
        int  v5254 = v15456->length;
        if (v5254 != v5252->length)
         { list * v4775;
          { list * v5962 = list::empty(Kernel.emptySet);
            { int  v5249 = 1;
              int  v7620 = (v5254-1);
              { OID gc_local;
                while ((v5249 <= v7620))
                { // HOHO, GC_LOOP not needed !
                  v5962->addFast((*(v5252))[v5249]);
                  ++v5249;
                  } 
                } 
              } 
            v4775 = GC_OBJECT(list,v5962);
            } 
          OID  v9533;
          { list * v9273;{ list * v5962 = list::empty(Kernel.emptySet);
              { int  v5249 = v5254;
                int  v7621 = v5252->length;
                { OID gc_local;
                  while ((v5249 <= v7621))
                  { // HOHO, GC_LOOP not needed !
                    v5962->addFast((*(v5252))[v5249]);
                    ++v5249;
                    } 
                  } 
                } 
              v9273 = GC_OBJECT(list,v5962);
              } 
            
            v9533=_oid_(v9273);} 
          v5252 = v4775->addFast(v9533);
          } 
        if ((v9268->inline_ask == CTRUE) && 
            (c_inline_ask_method(v9268,v5252) == CTRUE))
         Result = c_inline_method1(v9268,v5252,v15693);
        else { ClaireBoolean * v5242 = Optimize.OPT->allocation;
            OID  v5264 = Core.nil->value;
            (Optimize.OPT->allocation = CFALSE);
            { { list * v11455;
                { list * v5962 = list::empty(Kernel.emptySet);
                  { int  v5249 = 1;
                    int  v7623 = v5254;
                    { OID gc_local;
                      while ((v5249 <= v7623))
                      { GC_LOOP;
                        v5962->addFast(GC_OID(c_strict_code_any((*(v5252))[v5249],psort_any((*(v15456))[v5249]))));
                        ++v5249;
                        GC_UNLOOP;} 
                      } 
                    } 
                  v11455 = GC_OBJECT(list,v5962);
                  } 
                v5264 = Call_method_I_method(v9268,v11455);
                } 
              GC_OID(v5264);} 
            if (Optimize.OPT->allocation != CTRUE)
             (Optimize.OPT->allocation = v5242);
            Result = v5264;
            } 
          } 
      return (Result);} 
     } 
  else{ GC_BIND;
    ;{ OID Result = 0;
      Result = _oid_(open_message_property(v9268->selector,v5252));
      GC_UNBIND; return (Result);} 
    } 
  } 

OID  Call_method_I_method(method *v9268,list *v7082)
{ GC_BIND;
  if (BCONTAIN(status_I_restriction(v9268),1))
   { (Optimize.OPT->allocation = CTRUE);
    if (!BCONTAIN(v9268->status,6))
     { { bag *v_list; OID v_val;
        OID v5264,CLcount;
        v_list = v7082;
         v7082 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v5264 = (*(v_list))[CLcount];
          v_val = c_gc_I_any1(v5264);
          
          (*((list *) v7082))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v7082);} 
    } 
  else { ClaireBoolean * g0133I;
    { ClaireBoolean *v_and;
      { v_and = Optimize.OPT->allocation;
        if (v_and == CFALSE) g0133I =CFALSE; 
        else { { int  v13377;
            { list * v14338;
              { bag * v4916 = v7082;
                list * v11039 = ((list *) empty_bag(v4916));
                { ITERATE(v5264);
                  for (START(v4916); NEXT(v5264);)
                  if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v5264))) == CTRUE)
                   v11039->addFast(v5264);
                  } 
                v14338 = GC_OBJECT(list,v11039);
                } 
              v13377 = v14338->length;
              } 
            v_and = ((v13377 > 1) ? CTRUE : CFALSE);
            } 
          if (v_and == CFALSE) g0133I =CFALSE; 
          else g0133I = CTRUE;} 
        } 
      } 
    
    if (g0133I == CTRUE) { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = v7082;
           v7082 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v5264);
            
            (*((list *) v7082))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v7082);} 
      } 
  if (BCONTAIN(v9268->status,2))
   (Optimize.OPT->use_nth_equal = CTRUE);
  if (BCONTAIN(v9268->status,3))
   (Optimize.OPT->use_update = CTRUE);
  if (legal_ask_module(v9268->module_I,_oid_(v9268)) != CTRUE)
   tformat_string("in call ~S~S\n",0,list::alloc(2,_oid_(v9268->selector),_oid_(v7082)));
  { OID Result = 0;
    if (v7082->length == 1)
     { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
      (v2072->arg = v9268);
      (v2072->args = v7082);
      add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else if (v7082->length == 2)
     { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      (v2072->arg = v9268);
      (v2072->args = v7082);
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v2072->arg = v9268);
        (v2072->args = v7082);
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_method_Optimize(Call_method *v9268)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v15299;
      { { bag *v_list; OID v_val;
          OID v5264,CLcount;
          v_list = GC_OBJECT(list,v9268->args);
           v15299 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v5264 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v5264);
            
            (*((list *) v15299))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v15299);} 
      Result = use_range_method(v9268->arg,v15299);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_method_Optimize(Call_method *v9268)
{ return (_oid_(v9268));} 

ClaireBoolean * c_gc_ask_Call_method(Call_method *v9268)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { method * v5253 = v9268->arg;
      { ClaireBoolean *v_and;
        { v_and = not_any(_oid_((INHERIT(v5253->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v5253->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v5253->range))))));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = ((v5253->range != Kernel._float) ? CTRUE : CFALSE);
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = ((!BCONTAIN(status_I_restriction(v5253),5)) ? CTRUE : (((_inf_equal_type(v5253->range,Kernel._bag) != CTRUE) || 
                  (Optimize.OPT->loop_gc != CTRUE)) ? CTRUE : CFALSE));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = nth_integer(status_I_restriction(v5253),1);
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireBoolean *v_and;
                        { v_and = nth_integer(v5253->status,4);
                          if (v_and == CFALSE) v_or =CFALSE; 
                          else { { OID  v16260;
                              { OID gc_local;
                                ITERATE(v5264);
                                v16260= _oid_(CFALSE);
                                bag *v5264_support;
                                v5264_support = GC_OBJECT(list,v9268->args);
                                for (START(v5264_support); NEXT(v5264);)
                                { GC_LOOP;
                                  if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v5264))) == CTRUE)
                                   { v16260 = Kernel.ctrue;
                                    break;} 
                                  GC_UNLOOP;} 
                                } 
                              v_and = boolean_I_any(v16260);
                              } 
                            if (v_and == CFALSE) v_or =CFALSE; 
                            else v_or = CTRUE;} 
                          } 
                        } 
                      if (v_or == CTRUE) v_and =CTRUE; 
                      else v_and = CFALSE;} 
                    } 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireFunction * functional_I_method_Optimize(method *v9268)
{ GC_BIND;
  { ClaireFunction *Result ;
    { OID  v5246 = GC_OID(get_property(Kernel.functional,v9268));
      property * v5256 = v9268->selector;
      Result = ((INHERIT(OWNER(v5246),Kernel._function)) ?
        OBJECT(ClaireFunction,v5246) :
        make_function_string(string_v((*Optimize.function_name)(_oid_(v5256),
          _oid_(v9268->domain),
          v5246))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  nth_type_check_type(ClaireType *v15712,ClaireType *v15709,ClaireType *v15724)
{ GC_BIND;
  if (_inf_equal_type(v15724,GC_OBJECT(ClaireType,member_type(v15712))) != CTRUE)
   { warn_void();
    tformat_string("unsafe update on bag: type ~S into ~S\n",2,list::alloc(2,_oid_(v15724),_oid_(v15712)));
    } 
  { OID Result = 0;
    Result = _oid_(v15724);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_inline_ask_method(method *v9268,list *v5252)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { lambda * v5246 = GC_OBJECT(lambda,v9268->formula);
      list * v15453 = GC_OBJECT(list,v5246->vars);
      OID  v5264 = GC_OID(v5246->body);
      int  v5254 = 1;
      { OID  v837;
        { OID gc_local;
          ITERATE(v5263);
          v837= _oid_(CFALSE);
          bag *v5263_support;
          v5263_support = GC_OBJECT(list,v5246->vars);
          for (START(v5263_support); NEXT(v5263);)
          { GC_LOOP;
            if ((occurrence_any(v5264,OBJECT(Variable,v5263)) > 1) && 
                ((designated_ask_any((*(v5252))[v5254]) != CTRUE) && 
                  (!INHERIT(owner_any((*Kernel.range)(v5263)),Optimize._Pattern))))
             { v837 = Kernel.ctrue;
              break;} 
            else ++v5254;
              GC_UNLOOP;} 
          } 
        Result = not_any(v837);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  inline_optimize_ask_Call(Call *v9268)
{ GC_BIND;
  { OID Result = 0;
    { list * v5252 = GC_OBJECT(list,v9268->args);
      OID  v5253;
      { { list * v1798;
          { { bag *v_list; OID v_val;
              OID v5264,CLcount;
              v_list = v5252;
               v1798 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v5264 = (*(v_list))[CLcount];
                v_val = _oid_(set::alloc(1,v5264));
                
                (*((list *) v1798))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v1798);} 
          v5253 = restriction_I_property(v9268->selector,v1798,CTRUE);
          } 
        GC_OID(v5253);} 
      if (Kernel._method == OWNER(v5253))
       { { ClaireBoolean * g0140I;
          { ClaireBoolean *v_and;
            { v_and = OBJECT(method,v5253)->inline_ask;
              if (v_and == CFALSE) g0140I =CFALSE; 
              else { { OID  v7517;
                  { ITERATE(v5259);
                    v7517= _oid_(CFALSE);
                    for (START(OBJECT(restriction,v5253)->domain); NEXT(v5259);)
                    if (INHERIT(OBJECT(ClaireObject,v5259)->isa,Optimize._Pattern))
                     { v7517 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = boolean_I_any(v7517);
                  } 
                if (v_and == CFALSE) g0140I =CFALSE; 
                else { v_and = c_inline_ask_method(OBJECT(method,v5253),v5252);
                  if (v_and == CFALSE) g0140I =CFALSE; 
                  else g0140I = CTRUE;} 
                } 
              } 
            } 
          
          if (g0140I == CTRUE) Result = v5253;
            else Result = Kernel.cfalse;
          } 
        } 
      else Result = Kernel.cfalse;
        } 
    GC_UNBIND; return (Result);} 
  } 

