/* balalambdaexpression.c generated by balac, the Bala compiler
 * generated from balalambdaexpression.bala, do not modify */

/* balalambdaexpression.bala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "bala.h"
#include <balagee.h>
#include <glib-object.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_iterator_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterator_unref (var), NULL)))

struct _BalaLambdaExpressionPrivate {
	BalaMethod* _method;
	BalaList* parameters;
	BalaBlock* _statement_body;
	BalaExpression* _expression_body;
};

static gint BalaLambdaExpression_private_offset;
static gpointer bala_lambda_expression_parent_class = NULL;
static gint bala_lambda_expression_next_lambda_id;
static gint bala_lambda_expression_next_lambda_id = 0;

static void bala_lambda_expression_real_accept (BalaCodeNode* base,
                                         BalaCodeVisitor* visitor);
static void bala_lambda_expression_real_accept_children (BalaCodeNode* base,
                                                  BalaCodeVisitor* visitor);
static gboolean bala_lambda_expression_real_is_pure (BalaExpression* base);
static gboolean bala_lambda_expression_real_check (BalaCodeNode* base,
                                            BalaCodeContext* context);
static void bala_lambda_expression_real_emit (BalaCodeNode* base,
                                       BalaCodeGenerator* codegen);
static void bala_lambda_expression_real_get_used_variables (BalaCodeNode* base,
                                                     BalaCollection* collection);
static void bala_lambda_expression_finalize (BalaCodeNode * obj);
static GType bala_lambda_expression_get_type_once (void);

static inline gpointer
bala_lambda_expression_get_instance_private (BalaLambdaExpression* self)
{
	return G_STRUCT_MEMBER_P (self, BalaLambdaExpression_private_offset);
}

BalaExpression*
bala_lambda_expression_get_expression_body (BalaLambdaExpression* self)
{
	BalaExpression* result;
	BalaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_expression_body;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

void
bala_lambda_expression_set_expression_body (BalaLambdaExpression* self,
                                            BalaExpression* value)
{
	BalaExpression* _tmp0_;
	BalaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_expression_body);
	self->priv->_expression_body = _tmp0_;
	_tmp1_ = self->priv->_expression_body;
	if (_tmp1_ != NULL) {
		BalaExpression* _tmp2_;
		_tmp2_ = self->priv->_expression_body;
		bala_code_node_set_parent_node ((BalaCodeNode*) _tmp2_, (BalaCodeNode*) self);
	}
}

BalaBlock*
bala_lambda_expression_get_statement_body (BalaLambdaExpression* self)
{
	BalaBlock* result;
	BalaBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_statement_body;
	result = _tmp0_;
	return result;
}

void
bala_lambda_expression_set_statement_body (BalaLambdaExpression* self,
                                           BalaBlock* value)
{
	BalaBlock* _tmp0_;
	BalaBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_statement_body);
	self->priv->_statement_body = _tmp0_;
	_tmp1_ = self->priv->_statement_body;
	if (_tmp1_ != NULL) {
		BalaBlock* _tmp2_;
		_tmp2_ = self->priv->_statement_body;
		bala_code_node_set_parent_node ((BalaCodeNode*) _tmp2_, (BalaCodeNode*) self);
	}
}

BalaMethod*
bala_lambda_expression_get_method (BalaLambdaExpression* self)
{
	BalaMethod* result;
	BalaMethod* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_method;
	result = _tmp0_;
	return result;
}

void
bala_lambda_expression_set_method (BalaLambdaExpression* self,
                                   BalaMethod* value)
{
	BalaMethod* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_method);
	self->priv->_method = _tmp0_;
}

/**
 * Creates a new lambda expression.
 *
 * @param expression_body  expression body
 * @param source_reference reference to source code
 * @return                 newly created lambda expression
 */
BalaLambdaExpression*
bala_lambda_expression_construct (GType object_type,
                                  BalaExpression* expression_body,
                                  BalaSourceReference* source_reference)
{
	BalaLambdaExpression* self = NULL;
	g_return_val_if_fail (expression_body != NULL, NULL);
	self = (BalaLambdaExpression*) bala_expression_construct (object_type);
	bala_code_node_set_source_reference ((BalaCodeNode*) self, source_reference);
	bala_lambda_expression_set_expression_body (self, expression_body);
	return self;
}

BalaLambdaExpression*
bala_lambda_expression_new (BalaExpression* expression_body,
                            BalaSourceReference* source_reference)
{
	return bala_lambda_expression_construct (BALA_TYPE_LAMBDA_EXPRESSION, expression_body, source_reference);
}

/**
 * Creates a new lambda expression with statement body.
 *
 * @param statement_body   statement body
 * @param source_reference reference to source code
 * @return                 newly created lambda expression
 */
BalaLambdaExpression*
bala_lambda_expression_construct_with_statement_body (GType object_type,
                                                      BalaBlock* statement_body,
                                                      BalaSourceReference* source_reference)
{
	BalaLambdaExpression* self = NULL;
	g_return_val_if_fail (statement_body != NULL, NULL);
	self = (BalaLambdaExpression*) bala_expression_construct (object_type);
	bala_lambda_expression_set_statement_body (self, statement_body);
	bala_code_node_set_source_reference ((BalaCodeNode*) self, source_reference);
	return self;
}

BalaLambdaExpression*
bala_lambda_expression_new_with_statement_body (BalaBlock* statement_body,
                                                BalaSourceReference* source_reference)
{
	return bala_lambda_expression_construct_with_statement_body (BALA_TYPE_LAMBDA_EXPRESSION, statement_body, source_reference);
}

/**
 * Appends implicitly typed parameter.
 *
 * @param param parameter name
 */
void
bala_lambda_expression_add_parameter (BalaLambdaExpression* self,
                                      BalaParameter* param)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (param != NULL);
	_tmp0_ = self->priv->parameters;
	bala_collection_add ((BalaCollection*) _tmp0_, param);
}

/**
 * Returns the parameter list.
 *
 * @return parameter list
 */
BalaList*
bala_lambda_expression_get_parameters (BalaLambdaExpression* self)
{
	BalaList* _tmp0_;
	BalaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->parameters;
	result = _tmp0_;
	return result;
}

static void
bala_lambda_expression_real_accept (BalaCodeNode* base,
                                    BalaCodeVisitor* visitor)
{
	BalaLambdaExpression * self;
	self = (BalaLambdaExpression*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_lambda_expression (visitor, self);
	bala_code_visitor_visit_expression (visitor, (BalaExpression*) self);
}

static void
bala_lambda_expression_real_accept_children (BalaCodeNode* base,
                                             BalaCodeVisitor* visitor)
{
	BalaLambdaExpression * self;
	BalaMethod* _tmp0_;
	self = (BalaLambdaExpression*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = self->priv->_method;
	if (_tmp0_ == NULL) {
		BalaExpression* _tmp1_;
		BalaExpression* _tmp2_;
		_tmp1_ = bala_lambda_expression_get_expression_body (self);
		_tmp2_ = _tmp1_;
		if (_tmp2_ != NULL) {
			BalaExpression* _tmp3_;
			BalaExpression* _tmp4_;
			BalaExpression* _tmp5_;
			BalaExpression* _tmp6_;
			_tmp3_ = bala_lambda_expression_get_expression_body (self);
			_tmp4_ = _tmp3_;
			bala_code_node_accept ((BalaCodeNode*) _tmp4_, visitor);
			_tmp5_ = bala_lambda_expression_get_expression_body (self);
			_tmp6_ = _tmp5_;
			bala_code_visitor_visit_end_full_expression (visitor, _tmp6_);
		} else {
			BalaBlock* _tmp7_;
			BalaBlock* _tmp8_;
			_tmp7_ = bala_lambda_expression_get_statement_body (self);
			_tmp8_ = _tmp7_;
			if (_tmp8_ != NULL) {
				BalaBlock* _tmp9_;
				BalaBlock* _tmp10_;
				_tmp9_ = bala_lambda_expression_get_statement_body (self);
				_tmp10_ = _tmp9_;
				bala_code_node_accept ((BalaCodeNode*) _tmp10_, visitor);
			}
		}
	} else {
		BalaMethod* _tmp11_;
		_tmp11_ = self->priv->_method;
		bala_code_node_accept ((BalaCodeNode*) _tmp11_, visitor);
	}
}

static gboolean
bala_lambda_expression_real_is_pure (BalaExpression* base)
{
	BalaLambdaExpression * self;
	gboolean result = FALSE;
	self = (BalaLambdaExpression*) base;
	result = FALSE;
	return result;
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static gboolean
bala_lambda_expression_real_check (BalaCodeNode* base,
                                   BalaCodeContext* context)
{
	BalaLambdaExpression * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	BalaDataType* _tmp4_;
	BalaDataType* _tmp5_;
	BalaDelegate* cb = NULL;
	BalaDataType* _tmp18_;
	BalaDataType* _tmp19_;
	BalaDelegate* _tmp20_;
	BalaDelegate* _tmp21_;
	BalaDelegate* _tmp22_;
	BalaDataType* return_type = NULL;
	BalaDelegate* _tmp23_;
	BalaDataType* _tmp24_;
	BalaDataType* _tmp25_;
	BalaDataType* _tmp26_;
	BalaDataType* _tmp27_;
	BalaDataType* _tmp28_;
	gint _tmp29_;
	gchar* _tmp30_;
	gchar* _tmp31_;
	BalaDataType* _tmp32_;
	BalaSourceReference* _tmp33_;
	BalaSourceReference* _tmp34_;
	BalaMethod* _tmp35_;
	BalaMethod* _tmp36_;
	BalaMethod* _tmp37_;
	BalaDataType* _tmp38_;
	gboolean _tmp48_ = FALSE;
	BalaDelegate* _tmp49_;
	gboolean _tmp50_;
	gboolean _tmp51_;
	BalaMethod* _tmp95_;
	BalaSemanticAnalyzer* _tmp96_;
	BalaSemanticAnalyzer* _tmp97_;
	BalaSymbol* _tmp98_;
	BalaSymbol* _tmp99_;
	BalaScope* _tmp100_;
	BalaScope* _tmp101_;
	BalaMethod* _tmp102_;
	BalaList* lambda_params = NULL;
	BalaList* _tmp103_;
	BalaList* _tmp104_;
	BalaIterator* lambda_param_it = NULL;
	BalaList* _tmp105_;
	BalaIterator* _tmp106_;
	gboolean _tmp107_ = FALSE;
	BalaDelegate* _tmp108_;
	BalaDataType* _tmp109_;
	BalaDataType* _tmp110_;
	BalaIterator* _tmp166_;
	BalaArrayList* error_types = NULL;
	GEqualFunc _tmp169_;
	BalaArrayList* _tmp170_;
	BalaDelegate* _tmp171_;
	BalaArrayList* _tmp172_;
	BalaExpression* _tmp186_;
	BalaExpression* _tmp187_;
	BalaMethod* _tmp221_;
	BalaBlock* _tmp222_;
	BalaBlock* _tmp223_;
	BalaMethod* _tmp224_;
	BalaScope* _tmp225_;
	BalaScope* _tmp226_;
	BalaMethod* m = NULL;
	BalaSemanticAnalyzer* _tmp227_;
	BalaSemanticAnalyzer* _tmp228_;
	BalaSymbol* _tmp229_;
	BalaSymbol* _tmp230_;
	BalaMethod* _tmp231_;
	BalaMethod* _tmp232_;
	BalaMethod* _tmp256_;
	BalaMethod* _tmp257_;
	BalaMethod* _tmp258_;
	BalaMethodType* _tmp259_;
	BalaMethodType* _tmp260_;
	BalaDataType* _tmp261_;
	BalaDataType* _tmp262_;
	BalaDataType* _tmp263_;
	BalaDataType* _tmp264_;
	gboolean _tmp265_;
	gboolean _tmp266_;
	gboolean _tmp267_;
	gboolean _tmp268_;
	gboolean result = FALSE;
	self = (BalaLambdaExpression*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = bala_code_node_get_checked ((BalaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = bala_code_node_get_error ((BalaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	bala_code_node_set_checked ((BalaCodeNode*) self, TRUE);
	_tmp4_ = bala_expression_get_target_type ((BalaExpression*) self);
	_tmp5_ = _tmp4_;
	if (!BALA_IS_DELEGATE_TYPE (_tmp5_)) {
		BalaDataType* _tmp6_;
		BalaDataType* _tmp7_;
		bala_code_node_set_error ((BalaCodeNode*) self, TRUE);
		_tmp6_ = bala_expression_get_target_type ((BalaExpression*) self);
		_tmp7_ = _tmp6_;
		if (_tmp7_ != NULL) {
			BalaSourceReference* _tmp8_;
			BalaSourceReference* _tmp9_;
			BalaDataType* _tmp10_;
			BalaDataType* _tmp11_;
			gchar* _tmp12_;
			gchar* _tmp13_;
			gchar* _tmp14_;
			gchar* _tmp15_;
			_tmp8_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
			_tmp9_ = _tmp8_;
			_tmp10_ = bala_expression_get_target_type ((BalaExpression*) self);
			_tmp11_ = _tmp10_;
			_tmp12_ = bala_code_node_to_string ((BalaCodeNode*) _tmp11_);
			_tmp13_ = _tmp12_;
			_tmp14_ = g_strdup_printf ("Cannot convert lambda expression to `%s'", _tmp13_);
			_tmp15_ = _tmp14_;
			bala_report_error (_tmp9_, _tmp15_);
			_g_free0 (_tmp15_);
			_g_free0 (_tmp13_);
		} else {
			BalaSourceReference* _tmp16_;
			BalaSourceReference* _tmp17_;
			_tmp16_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
			_tmp17_ = _tmp16_;
			bala_report_error (_tmp17_, "lambda expression not allowed in this context");
		}
		result = FALSE;
		return result;
	}
	_tmp18_ = bala_expression_get_target_type ((BalaExpression*) self);
	_tmp19_ = _tmp18_;
	_tmp20_ = bala_delegate_type_get_delegate_symbol (G_TYPE_CHECK_INSTANCE_CAST (_tmp19_, BALA_TYPE_DELEGATE_TYPE, BalaDelegateType));
	_tmp21_ = _tmp20_;
	_tmp22_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp21_, BALA_TYPE_DELEGATE, BalaDelegate));
	cb = _tmp22_;
	_tmp23_ = cb;
	_tmp24_ = bala_callable_get_return_type ((BalaCallable*) _tmp23_);
	_tmp25_ = _tmp24_;
	_tmp26_ = bala_expression_get_target_type ((BalaExpression*) self);
	_tmp27_ = _tmp26_;
	_tmp28_ = bala_data_type_get_actual_type (_tmp25_, _tmp27_, NULL, (BalaCodeNode*) self);
	return_type = _tmp28_;
	_tmp29_ = bala_lambda_expression_next_lambda_id;
	bala_lambda_expression_next_lambda_id = _tmp29_ + 1;
	_tmp30_ = g_strdup_printf ("_lambda%d_", _tmp29_);
	_tmp31_ = _tmp30_;
	_tmp32_ = return_type;
	_tmp33_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp34_ = _tmp33_;
	_tmp35_ = bala_method_new (_tmp31_, _tmp32_, _tmp34_, NULL);
	_tmp36_ = _tmp35_;
	bala_lambda_expression_set_method (self, _tmp36_);
	_bala_code_node_unref0 (_tmp36_);
	_g_free0 (_tmp31_);
	_tmp37_ = self->priv->_method;
	bala_symbol_set_used ((BalaSymbol*) _tmp37_, TRUE);
	_tmp38_ = return_type;
	if (BALA_IS_ARRAY_TYPE (_tmp38_)) {
		BalaMethod* _tmp39_;
		BalaDelegate* _tmp40_;
		BalaMethod* _tmp41_;
		BalaDelegate* _tmp42_;
		BalaMethod* _tmp43_;
		BalaDelegate* _tmp44_;
		_tmp39_ = self->priv->_method;
		_tmp40_ = cb;
		bala_code_node_copy_attribute_bool ((BalaCodeNode*) _tmp39_, (BalaCodeNode*) _tmp40_, "CCode", "array_length");
		_tmp41_ = self->priv->_method;
		_tmp42_ = cb;
		bala_code_node_copy_attribute_bool ((BalaCodeNode*) _tmp41_, (BalaCodeNode*) _tmp42_, "CCode", "array_null_terminated");
		_tmp43_ = self->priv->_method;
		_tmp44_ = cb;
		bala_code_node_copy_attribute_string ((BalaCodeNode*) _tmp43_, (BalaCodeNode*) _tmp44_, "CCode", "array_length_type");
	} else {
		BalaDataType* _tmp45_;
		_tmp45_ = return_type;
		if (BALA_IS_DELEGATE_TYPE (_tmp45_)) {
			BalaMethod* _tmp46_;
			BalaDelegate* _tmp47_;
			_tmp46_ = self->priv->_method;
			_tmp47_ = cb;
			bala_code_node_copy_attribute_bool ((BalaCodeNode*) _tmp46_, (BalaCodeNode*) _tmp47_, "CCode", "delegate_target");
		}
	}
	_tmp49_ = cb;
	_tmp50_ = bala_delegate_get_has_target (_tmp49_);
	_tmp51_ = _tmp50_;
	if (!_tmp51_) {
		_tmp48_ = TRUE;
	} else {
		BalaSemanticAnalyzer* _tmp52_;
		BalaSemanticAnalyzer* _tmp53_;
		_tmp52_ = bala_code_context_get_analyzer (context);
		_tmp53_ = _tmp52_;
		_tmp48_ = !bala_semantic_analyzer_is_in_instance_method (_tmp53_);
	}
	if (_tmp48_) {
		BalaMethod* _tmp54_;
		_tmp54_ = self->priv->_method;
		bala_method_set_binding (_tmp54_, BALA_MEMBER_BINDING_STATIC);
	} else {
		BalaSymbol* sym = NULL;
		BalaSemanticAnalyzer* _tmp55_;
		BalaSemanticAnalyzer* _tmp56_;
		BalaSymbol* _tmp57_;
		BalaSymbol* _tmp58_;
		BalaSymbol* _tmp59_;
		_tmp55_ = bala_code_context_get_analyzer (context);
		_tmp56_ = _tmp55_;
		_tmp57_ = bala_semantic_analyzer_get_current_symbol (_tmp56_);
		_tmp58_ = _tmp57_;
		_tmp59_ = _bala_code_node_ref0 (_tmp58_);
		sym = _tmp59_;
		while (TRUE) {
			BalaMethod* _tmp60_;
			BalaParameter* _tmp61_;
			BalaParameter* _tmp62_;
			BalaSymbol* _tmp63_;
			BalaSymbol* _tmp91_;
			BalaSymbol* _tmp92_;
			BalaSymbol* _tmp93_;
			BalaSymbol* _tmp94_;
			_tmp60_ = self->priv->_method;
			_tmp61_ = bala_method_get_this_parameter (_tmp60_);
			_tmp62_ = _tmp61_;
			if (!(_tmp62_ == NULL)) {
				break;
			}
			_tmp63_ = sym;
			if (BALA_IS_PROPERTY (_tmp63_)) {
				BalaProperty* prop = NULL;
				BalaSymbol* _tmp64_;
				BalaProperty* _tmp65_;
				BalaMethod* _tmp66_;
				BalaProperty* _tmp67_;
				BalaParameter* _tmp68_;
				BalaParameter* _tmp69_;
				_tmp64_ = sym;
				_tmp65_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp64_, BALA_TYPE_PROPERTY, BalaProperty));
				prop = _tmp65_;
				_tmp66_ = self->priv->_method;
				_tmp67_ = prop;
				_tmp68_ = bala_property_get_this_parameter (_tmp67_);
				_tmp69_ = _tmp68_;
				bala_method_set_this_parameter (_tmp66_, _tmp69_);
				_bala_code_node_unref0 (prop);
			} else {
				BalaSymbol* _tmp70_;
				_tmp70_ = sym;
				if (BALA_IS_CONSTRUCTOR (_tmp70_)) {
					BalaConstructor* c = NULL;
					BalaSymbol* _tmp71_;
					BalaConstructor* _tmp72_;
					BalaMethod* _tmp73_;
					BalaConstructor* _tmp74_;
					BalaParameter* _tmp75_;
					BalaParameter* _tmp76_;
					_tmp71_ = sym;
					_tmp72_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp71_, BALA_TYPE_CONSTRUCTOR, BalaConstructor));
					c = _tmp72_;
					_tmp73_ = self->priv->_method;
					_tmp74_ = c;
					_tmp75_ = bala_constructor_get_this_parameter (_tmp74_);
					_tmp76_ = _tmp75_;
					bala_method_set_this_parameter (_tmp73_, _tmp76_);
					_bala_code_node_unref0 (c);
				} else {
					BalaSymbol* _tmp77_;
					_tmp77_ = sym;
					if (BALA_IS_DESTRUCTOR (_tmp77_)) {
						BalaDestructor* d = NULL;
						BalaSymbol* _tmp78_;
						BalaDestructor* _tmp79_;
						BalaMethod* _tmp80_;
						BalaDestructor* _tmp81_;
						BalaParameter* _tmp82_;
						BalaParameter* _tmp83_;
						_tmp78_ = sym;
						_tmp79_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp78_, BALA_TYPE_DESTRUCTOR, BalaDestructor));
						d = _tmp79_;
						_tmp80_ = self->priv->_method;
						_tmp81_ = d;
						_tmp82_ = bala_destructor_get_this_parameter (_tmp81_);
						_tmp83_ = _tmp82_;
						bala_method_set_this_parameter (_tmp80_, _tmp83_);
						_bala_code_node_unref0 (d);
					} else {
						BalaSymbol* _tmp84_;
						_tmp84_ = sym;
						if (BALA_IS_METHOD (_tmp84_)) {
							BalaMethod* m = NULL;
							BalaSymbol* _tmp85_;
							BalaMethod* _tmp86_;
							BalaMethod* _tmp87_;
							BalaMethod* _tmp88_;
							BalaParameter* _tmp89_;
							BalaParameter* _tmp90_;
							_tmp85_ = sym;
							_tmp86_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp85_, BALA_TYPE_METHOD, BalaMethod));
							m = _tmp86_;
							_tmp87_ = self->priv->_method;
							_tmp88_ = m;
							_tmp89_ = bala_method_get_this_parameter (_tmp88_);
							_tmp90_ = _tmp89_;
							bala_method_set_this_parameter (_tmp87_, _tmp90_);
							_bala_code_node_unref0 (m);
						}
					}
				}
			}
			_tmp91_ = sym;
			_tmp92_ = bala_symbol_get_parent_symbol (_tmp91_);
			_tmp93_ = _tmp92_;
			_tmp94_ = _bala_code_node_ref0 (_tmp93_);
			_bala_code_node_unref0 (sym);
			sym = _tmp94_;
		}
		_bala_code_node_unref0 (sym);
	}
	_tmp95_ = self->priv->_method;
	_tmp96_ = bala_code_context_get_analyzer (context);
	_tmp97_ = _tmp96_;
	_tmp98_ = bala_semantic_analyzer_get_current_symbol (_tmp97_);
	_tmp99_ = _tmp98_;
	_tmp100_ = bala_symbol_get_scope (_tmp99_);
	_tmp101_ = _tmp100_;
	bala_symbol_set_owner ((BalaSymbol*) _tmp95_, _tmp101_);
	_tmp102_ = self->priv->_method;
	bala_code_node_set_parent_node ((BalaCodeNode*) _tmp102_, (BalaCodeNode*) self);
	_tmp103_ = bala_lambda_expression_get_parameters (self);
	_tmp104_ = _bala_iterable_ref0 (_tmp103_);
	lambda_params = _tmp104_;
	_tmp105_ = lambda_params;
	_tmp106_ = bala_iterable_iterator ((BalaIterable*) _tmp105_);
	lambda_param_it = _tmp106_;
	_tmp108_ = cb;
	_tmp109_ = bala_delegate_get_sender_type (_tmp108_);
	_tmp110_ = _tmp109_;
	if (_tmp110_ != NULL) {
		BalaList* _tmp111_;
		gint _tmp112_;
		gint _tmp113_;
		BalaDelegate* _tmp114_;
		BalaList* _tmp115_;
		gint _tmp116_;
		gint _tmp117_;
		_tmp111_ = lambda_params;
		_tmp112_ = bala_collection_get_size ((BalaCollection*) _tmp111_);
		_tmp113_ = _tmp112_;
		_tmp114_ = cb;
		_tmp115_ = bala_callable_get_parameters ((BalaCallable*) _tmp114_);
		_tmp116_ = bala_collection_get_size ((BalaCollection*) _tmp115_);
		_tmp117_ = _tmp116_;
		_tmp107_ = _tmp113_ == (_tmp117_ + 1);
	} else {
		_tmp107_ = FALSE;
	}
	if (_tmp107_) {
		BalaIterator* _tmp118_;
		BalaParameter* lambda_param = NULL;
		BalaIterator* _tmp119_;
		gpointer _tmp120_;
		BalaParameter* _tmp121_;
		BalaDelegate* _tmp122_;
		BalaDataType* _tmp123_;
		BalaDataType* _tmp124_;
		BalaMethod* _tmp125_;
		BalaParameter* _tmp126_;
		_tmp118_ = lambda_param_it;
		bala_iterator_next (_tmp118_);
		_tmp119_ = lambda_param_it;
		_tmp120_ = bala_iterator_get (_tmp119_);
		lambda_param = (BalaParameter*) _tmp120_;
		_tmp121_ = lambda_param;
		_tmp122_ = cb;
		_tmp123_ = bala_delegate_get_sender_type (_tmp122_);
		_tmp124_ = _tmp123_;
		bala_variable_set_variable_type ((BalaVariable*) _tmp121_, _tmp124_);
		_tmp125_ = self->priv->_method;
		_tmp126_ = lambda_param;
		bala_callable_add_parameter ((BalaCallable*) _tmp125_, _tmp126_);
		_bala_code_node_unref0 (lambda_param);
	}
	{
		BalaList* _cb_param_list = NULL;
		BalaDelegate* _tmp127_;
		BalaList* _tmp128_;
		BalaList* _tmp129_;
		gint _cb_param_size = 0;
		BalaList* _tmp130_;
		gint _tmp131_;
		gint _tmp132_;
		gint _cb_param_index = 0;
		_tmp127_ = cb;
		_tmp128_ = bala_callable_get_parameters ((BalaCallable*) _tmp127_);
		_tmp129_ = _bala_iterable_ref0 (_tmp128_);
		_cb_param_list = _tmp129_;
		_tmp130_ = _cb_param_list;
		_tmp131_ = bala_collection_get_size ((BalaCollection*) _tmp130_);
		_tmp132_ = _tmp131_;
		_cb_param_size = _tmp132_;
		_cb_param_index = -1;
		while (TRUE) {
			gint _tmp133_;
			gint _tmp134_;
			BalaParameter* cb_param = NULL;
			BalaList* _tmp135_;
			gpointer _tmp136_;
			BalaIterator* _tmp137_;
			BalaParameter* lambda_param = NULL;
			BalaIterator* _tmp138_;
			gpointer _tmp139_;
			BalaParameter* _tmp140_;
			BalaParameterDirection _tmp141_;
			BalaParameterDirection _tmp142_;
			BalaParameter* _tmp143_;
			BalaParameterDirection _tmp144_;
			BalaParameterDirection _tmp145_;
			BalaParameter* _tmp154_;
			BalaParameter* _tmp155_;
			BalaDataType* _tmp156_;
			BalaDataType* _tmp157_;
			BalaDataType* _tmp158_;
			BalaDataType* _tmp159_;
			BalaDataType* _tmp160_;
			BalaDataType* _tmp161_;
			BalaParameter* _tmp162_;
			BalaParameter* _tmp163_;
			BalaMethod* _tmp164_;
			BalaParameter* _tmp165_;
			_cb_param_index = _cb_param_index + 1;
			_tmp133_ = _cb_param_index;
			_tmp134_ = _cb_param_size;
			if (!(_tmp133_ < _tmp134_)) {
				break;
			}
			_tmp135_ = _cb_param_list;
			_tmp136_ = bala_list_get (_tmp135_, _cb_param_index);
			cb_param = (BalaParameter*) _tmp136_;
			_tmp137_ = lambda_param_it;
			if (!bala_iterator_next (_tmp137_)) {
				_bala_code_node_unref0 (cb_param);
				break;
			}
			_tmp138_ = lambda_param_it;
			_tmp139_ = bala_iterator_get (_tmp138_);
			lambda_param = (BalaParameter*) _tmp139_;
			_tmp140_ = lambda_param;
			_tmp141_ = bala_parameter_get_direction (_tmp140_);
			_tmp142_ = _tmp141_;
			_tmp143_ = cb_param;
			_tmp144_ = bala_parameter_get_direction (_tmp143_);
			_tmp145_ = _tmp144_;
			if (_tmp142_ != _tmp145_) {
				BalaParameter* _tmp146_;
				BalaSourceReference* _tmp147_;
				BalaSourceReference* _tmp148_;
				BalaParameter* _tmp149_;
				const gchar* _tmp150_;
				const gchar* _tmp151_;
				gchar* _tmp152_;
				gchar* _tmp153_;
				bala_code_node_set_error ((BalaCodeNode*) self, TRUE);
				_tmp146_ = lambda_param;
				_tmp147_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp146_);
				_tmp148_ = _tmp147_;
				_tmp149_ = lambda_param;
				_tmp150_ = bala_symbol_get_name ((BalaSymbol*) _tmp149_);
				_tmp151_ = _tmp150_;
				_tmp152_ = g_strdup_printf ("direction of parameter `%s' is incompatible with the target delegate", _tmp151_);
				_tmp153_ = _tmp152_;
				bala_report_error (_tmp148_, _tmp153_);
				_g_free0 (_tmp153_);
			}
			_tmp154_ = lambda_param;
			_tmp155_ = cb_param;
			_tmp156_ = bala_variable_get_variable_type ((BalaVariable*) _tmp155_);
			_tmp157_ = _tmp156_;
			_tmp158_ = bala_expression_get_target_type ((BalaExpression*) self);
			_tmp159_ = _tmp158_;
			_tmp160_ = bala_data_type_get_actual_type (_tmp157_, _tmp159_, NULL, (BalaCodeNode*) self);
			_tmp161_ = _tmp160_;
			bala_variable_set_variable_type ((BalaVariable*) _tmp154_, _tmp161_);
			_bala_code_node_unref0 (_tmp161_);
			_tmp162_ = lambda_param;
			_tmp163_ = cb_param;
			bala_parameter_set_base_parameter (_tmp162_, _tmp163_);
			_tmp164_ = self->priv->_method;
			_tmp165_ = lambda_param;
			bala_callable_add_parameter ((BalaCallable*) _tmp164_, _tmp165_);
			_bala_code_node_unref0 (lambda_param);
			_bala_code_node_unref0 (cb_param);
		}
		_bala_iterable_unref0 (_cb_param_list);
	}
	_tmp166_ = lambda_param_it;
	if (bala_iterator_next (_tmp166_)) {
		BalaSourceReference* _tmp167_;
		BalaSourceReference* _tmp168_;
		bala_code_node_set_error ((BalaCodeNode*) self, TRUE);
		_tmp167_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
		_tmp168_ = _tmp167_;
		bala_report_error (_tmp168_, "lambda expression: too many parameters");
		result = FALSE;
		_bala_iterator_unref0 (lambda_param_it);
		_bala_iterable_unref0 (lambda_params);
		_bala_code_node_unref0 (return_type);
		_bala_code_node_unref0 (cb);
		return result;
	}
	_tmp169_ = g_direct_equal;
	_tmp170_ = bala_array_list_new (BALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp169_);
	error_types = _tmp170_;
	_tmp171_ = cb;
	_tmp172_ = error_types;
	bala_code_node_get_error_types ((BalaCodeNode*) _tmp171_, (BalaCollection*) _tmp172_, NULL);
	{
		BalaArrayList* _error_type_list = NULL;
		BalaArrayList* _tmp173_;
		BalaArrayList* _tmp174_;
		gint _error_type_size = 0;
		BalaArrayList* _tmp175_;
		gint _tmp176_;
		gint _tmp177_;
		gint _error_type_index = 0;
		_tmp173_ = error_types;
		_tmp174_ = _bala_iterable_ref0 (_tmp173_);
		_error_type_list = _tmp174_;
		_tmp175_ = _error_type_list;
		_tmp176_ = bala_collection_get_size ((BalaCollection*) _tmp175_);
		_tmp177_ = _tmp176_;
		_error_type_size = _tmp177_;
		_error_type_index = -1;
		while (TRUE) {
			gint _tmp178_;
			gint _tmp179_;
			BalaDataType* error_type = NULL;
			BalaArrayList* _tmp180_;
			gpointer _tmp181_;
			BalaMethod* _tmp182_;
			BalaDataType* _tmp183_;
			BalaDataType* _tmp184_;
			BalaDataType* _tmp185_;
			_error_type_index = _error_type_index + 1;
			_tmp178_ = _error_type_index;
			_tmp179_ = _error_type_size;
			if (!(_tmp178_ < _tmp179_)) {
				break;
			}
			_tmp180_ = _error_type_list;
			_tmp181_ = bala_list_get ((BalaList*) _tmp180_, _error_type_index);
			error_type = (BalaDataType*) _tmp181_;
			_tmp182_ = self->priv->_method;
			_tmp183_ = error_type;
			_tmp184_ = bala_data_type_copy (_tmp183_);
			_tmp185_ = _tmp184_;
			bala_method_add_error_type (_tmp182_, _tmp185_);
			_bala_code_node_unref0 (_tmp185_);
			_bala_code_node_unref0 (error_type);
		}
		_bala_iterable_unref0 (_error_type_list);
	}
	_tmp186_ = bala_lambda_expression_get_expression_body (self);
	_tmp187_ = _tmp186_;
	if (_tmp187_ != NULL) {
		BalaBlock* block = NULL;
		BalaSourceReference* _tmp188_;
		BalaSourceReference* _tmp189_;
		BalaBlock* _tmp190_;
		BalaBlock* _tmp191_;
		BalaScope* _tmp192_;
		BalaScope* _tmp193_;
		BalaMethod* _tmp194_;
		BalaScope* _tmp195_;
		BalaScope* _tmp196_;
		BalaMethod* _tmp197_;
		BalaDataType* _tmp198_;
		BalaDataType* _tmp199_;
		BalaTypeSymbol* _tmp200_;
		BalaTypeSymbol* _tmp201_;
		BalaMethod* _tmp216_;
		BalaBlock* _tmp217_;
		_tmp188_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
		_tmp189_ = _tmp188_;
		_tmp190_ = bala_block_new (_tmp189_);
		block = _tmp190_;
		_tmp191_ = block;
		_tmp192_ = bala_symbol_get_scope ((BalaSymbol*) _tmp191_);
		_tmp193_ = _tmp192_;
		_tmp194_ = self->priv->_method;
		_tmp195_ = bala_symbol_get_scope ((BalaSymbol*) _tmp194_);
		_tmp196_ = _tmp195_;
		bala_scope_set_parent_scope (_tmp193_, _tmp196_);
		_tmp197_ = self->priv->_method;
		_tmp198_ = bala_callable_get_return_type ((BalaCallable*) _tmp197_);
		_tmp199_ = _tmp198_;
		_tmp200_ = bala_data_type_get_type_symbol (_tmp199_);
		_tmp201_ = _tmp200_;
		if (_tmp201_ != NULL) {
			BalaBlock* _tmp202_;
			BalaExpression* _tmp203_;
			BalaExpression* _tmp204_;
			BalaSourceReference* _tmp205_;
			BalaSourceReference* _tmp206_;
			BalaReturnStatement* _tmp207_;
			BalaReturnStatement* _tmp208_;
			_tmp202_ = block;
			_tmp203_ = bala_lambda_expression_get_expression_body (self);
			_tmp204_ = _tmp203_;
			_tmp205_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
			_tmp206_ = _tmp205_;
			_tmp207_ = bala_return_statement_new (_tmp204_, _tmp206_);
			_tmp208_ = _tmp207_;
			bala_block_add_statement (_tmp202_, (BalaStatement*) _tmp208_);
			_bala_code_node_unref0 (_tmp208_);
		} else {
			BalaBlock* _tmp209_;
			BalaExpression* _tmp210_;
			BalaExpression* _tmp211_;
			BalaSourceReference* _tmp212_;
			BalaSourceReference* _tmp213_;
			BalaExpressionStatement* _tmp214_;
			BalaExpressionStatement* _tmp215_;
			_tmp209_ = block;
			_tmp210_ = bala_lambda_expression_get_expression_body (self);
			_tmp211_ = _tmp210_;
			_tmp212_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
			_tmp213_ = _tmp212_;
			_tmp214_ = bala_expression_statement_new (_tmp211_, _tmp213_);
			_tmp215_ = _tmp214_;
			bala_block_add_statement (_tmp209_, (BalaStatement*) _tmp215_);
			_bala_code_node_unref0 (_tmp215_);
		}
		_tmp216_ = self->priv->_method;
		_tmp217_ = block;
		bala_subroutine_set_body ((BalaSubroutine*) _tmp216_, _tmp217_);
		_bala_code_node_unref0 (block);
	} else {
		BalaMethod* _tmp218_;
		BalaBlock* _tmp219_;
		BalaBlock* _tmp220_;
		_tmp218_ = self->priv->_method;
		_tmp219_ = bala_lambda_expression_get_statement_body (self);
		_tmp220_ = _tmp219_;
		bala_subroutine_set_body ((BalaSubroutine*) _tmp218_, _tmp220_);
	}
	_tmp221_ = self->priv->_method;
	_tmp222_ = bala_subroutine_get_body ((BalaSubroutine*) _tmp221_);
	_tmp223_ = _tmp222_;
	_tmp224_ = self->priv->_method;
	_tmp225_ = bala_symbol_get_scope ((BalaSymbol*) _tmp224_);
	_tmp226_ = _tmp225_;
	bala_symbol_set_owner ((BalaSymbol*) _tmp223_, _tmp226_);
	_tmp227_ = bala_code_context_get_analyzer (context);
	_tmp228_ = _tmp227_;
	_tmp229_ = bala_semantic_analyzer_get_current_symbol (_tmp228_);
	_tmp230_ = _tmp229_;
	_tmp231_ = bala_semantic_analyzer_find_parent_method (_tmp230_);
	m = _tmp231_;
	_tmp232_ = m;
	if (_tmp232_ != NULL) {
		{
			BalaList* _type_param_list = NULL;
			BalaMethod* _tmp233_;
			BalaList* _tmp234_;
			BalaList* _tmp235_;
			gint _type_param_size = 0;
			BalaList* _tmp236_;
			gint _tmp237_;
			gint _tmp238_;
			gint _type_param_index = 0;
			_tmp233_ = m;
			_tmp234_ = bala_method_get_type_parameters (_tmp233_);
			_tmp235_ = _bala_iterable_ref0 (_tmp234_);
			_type_param_list = _tmp235_;
			_tmp236_ = _type_param_list;
			_tmp237_ = bala_collection_get_size ((BalaCollection*) _tmp236_);
			_tmp238_ = _tmp237_;
			_type_param_size = _tmp238_;
			_type_param_index = -1;
			while (TRUE) {
				gint _tmp239_;
				gint _tmp240_;
				BalaTypeParameter* type_param = NULL;
				BalaList* _tmp241_;
				gpointer _tmp242_;
				BalaMethod* _tmp243_;
				BalaTypeParameter* _tmp244_;
				const gchar* _tmp245_;
				const gchar* _tmp246_;
				BalaTypeParameter* _tmp247_;
				BalaSourceReference* _tmp248_;
				BalaSourceReference* _tmp249_;
				BalaTypeParameter* _tmp250_;
				BalaTypeParameter* _tmp251_;
				BalaMethod* _tmp252_;
				BalaMethod* _tmp253_;
				BalaBlock* _tmp254_;
				BalaBlock* _tmp255_;
				_type_param_index = _type_param_index + 1;
				_tmp239_ = _type_param_index;
				_tmp240_ = _type_param_size;
				if (!(_tmp239_ < _tmp240_)) {
					break;
				}
				_tmp241_ = _type_param_list;
				_tmp242_ = bala_list_get (_tmp241_, _type_param_index);
				type_param = (BalaTypeParameter*) _tmp242_;
				_tmp243_ = self->priv->_method;
				_tmp244_ = type_param;
				_tmp245_ = bala_symbol_get_name ((BalaSymbol*) _tmp244_);
				_tmp246_ = _tmp245_;
				_tmp247_ = type_param;
				_tmp248_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp247_);
				_tmp249_ = _tmp248_;
				_tmp250_ = bala_typeparameter_new (_tmp246_, _tmp249_);
				_tmp251_ = _tmp250_;
				bala_method_add_type_parameter (_tmp243_, _tmp251_);
				_bala_code_node_unref0 (_tmp251_);
				_tmp252_ = self->priv->_method;
				bala_method_set_closure (_tmp252_, TRUE);
				_tmp253_ = m;
				_tmp254_ = bala_subroutine_get_body ((BalaSubroutine*) _tmp253_);
				_tmp255_ = _tmp254_;
				bala_block_set_captured (_tmp255_, TRUE);
				_bala_code_node_unref0 (type_param);
			}
			_bala_iterable_unref0 (_type_param_list);
		}
	}
	_tmp256_ = self->priv->_method;
	bala_expression_set_symbol_reference ((BalaExpression*) self, (BalaSymbol*) _tmp256_);
	_tmp257_ = self->priv->_method;
	bala_code_node_check ((BalaCodeNode*) _tmp257_, context);
	_tmp258_ = self->priv->_method;
	_tmp259_ = bala_method_type_new (_tmp258_);
	_tmp260_ = _tmp259_;
	bala_expression_set_value_type ((BalaExpression*) self, (BalaDataType*) _tmp260_);
	_bala_code_node_unref0 (_tmp260_);
	_tmp261_ = bala_expression_get_value_type ((BalaExpression*) self);
	_tmp262_ = _tmp261_;
	_tmp263_ = bala_expression_get_target_type ((BalaExpression*) self);
	_tmp264_ = _tmp263_;
	_tmp265_ = bala_data_type_get_value_owned (_tmp264_);
	_tmp266_ = _tmp265_;
	bala_data_type_set_value_owned (_tmp262_, _tmp266_);
	_tmp267_ = bala_code_node_get_error ((BalaCodeNode*) self);
	_tmp268_ = _tmp267_;
	result = !_tmp268_;
	_bala_iterable_unref0 (error_types);
	_bala_iterator_unref0 (lambda_param_it);
	_bala_iterable_unref0 (lambda_params);
	_bala_code_node_unref0 (return_type);
	_bala_code_node_unref0 (cb);
	return result;
}

static void
bala_lambda_expression_real_emit (BalaCodeNode* base,
                                  BalaCodeGenerator* codegen)
{
	BalaLambdaExpression * self;
	self = (BalaLambdaExpression*) base;
	g_return_if_fail (codegen != NULL);
	bala_code_visitor_visit_lambda_expression ((BalaCodeVisitor*) codegen, self);
	bala_code_visitor_visit_expression ((BalaCodeVisitor*) codegen, (BalaExpression*) self);
}

static void
bala_lambda_expression_real_get_used_variables (BalaCodeNode* base,
                                                BalaCollection* collection)
{
	BalaLambdaExpression * self;
	gboolean _tmp0_ = FALSE;
	BalaMethod* _tmp1_;
	self = (BalaLambdaExpression*) base;
	g_return_if_fail (collection != NULL);
	_tmp1_ = self->priv->_method;
	if (_tmp1_ != NULL) {
		BalaMethod* _tmp2_;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp2_ = self->priv->_method;
		_tmp3_ = bala_method_get_closure (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = _tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		BalaMethod* _tmp5_;
		_tmp5_ = self->priv->_method;
		bala_method_get_captured_variables (_tmp5_, G_TYPE_CHECK_INSTANCE_CAST (collection, BALA_TYPE_COLLECTION, BalaCollection));
	}
}

static void
bala_lambda_expression_class_init (BalaLambdaExpressionClass * klass,
                                   gpointer klass_data)
{
	bala_lambda_expression_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_lambda_expression_finalize;
	g_type_class_adjust_private_offset (klass, &BalaLambdaExpression_private_offset);
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_lambda_expression_real_accept;
	((BalaCodeNodeClass *) klass)->accept_children = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_lambda_expression_real_accept_children;
	((BalaExpressionClass *) klass)->is_pure = (gboolean (*) (BalaExpression*)) bala_lambda_expression_real_is_pure;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_lambda_expression_real_check;
	((BalaCodeNodeClass *) klass)->emit = (void (*) (BalaCodeNode*, BalaCodeGenerator*)) bala_lambda_expression_real_emit;
	((BalaCodeNodeClass *) klass)->get_used_variables = (void (*) (BalaCodeNode*, BalaCollection*)) bala_lambda_expression_real_get_used_variables;
}

static void
bala_lambda_expression_instance_init (BalaLambdaExpression * self,
                                      gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	self->priv = bala_lambda_expression_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_PARAMETER, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp0_);
	self->priv->parameters = (BalaList*) _tmp1_;
}

static void
bala_lambda_expression_finalize (BalaCodeNode * obj)
{
	BalaLambdaExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_LAMBDA_EXPRESSION, BalaLambdaExpression);
	_bala_code_node_unref0 (self->priv->_method);
	_bala_iterable_unref0 (self->priv->parameters);
	_bala_code_node_unref0 (self->priv->_statement_body);
	_bala_code_node_unref0 (self->priv->_expression_body);
	BALA_CODE_NODE_CLASS (bala_lambda_expression_parent_class)->finalize (obj);
}

/**
 * Represents a lambda expression in the source code.
 *
 * Lambda expressions are anonymous methods with implicitly typed parameters.
 */
static GType
bala_lambda_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaLambdaExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_lambda_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaLambdaExpression), 0, (GInstanceInitFunc) bala_lambda_expression_instance_init, NULL };
	GType bala_lambda_expression_type_id;
	bala_lambda_expression_type_id = g_type_register_static (BALA_TYPE_EXPRESSION, "BalaLambdaExpression", &g_define_type_info, 0);
	BalaLambdaExpression_private_offset = g_type_add_instance_private (bala_lambda_expression_type_id, sizeof (BalaLambdaExpressionPrivate));
	return bala_lambda_expression_type_id;
}

GType
bala_lambda_expression_get_type (void)
{
	static volatile gsize bala_lambda_expression_type_id__volatile = 0;
	if (g_once_init_enter (&bala_lambda_expression_type_id__volatile)) {
		GType bala_lambda_expression_type_id;
		bala_lambda_expression_type_id = bala_lambda_expression_get_type_once ();
		g_once_init_leave (&bala_lambda_expression_type_id__volatile, bala_lambda_expression_type_id);
	}
	return bala_lambda_expression_type_id__volatile;
}

