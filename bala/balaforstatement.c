/* balaforstatement.c generated by balac, the Bala compiler
 * generated from balaforstatement.bala, do not modify */

/* balaforstatement.bala
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

#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _BalaForStatementPrivate {
	BalaList* initializer;
	BalaList* iterator;
	BalaExpression* _condition;
	BalaBlock* _body;
};

static gint BalaForStatement_private_offset;
static gpointer bala_for_statement_parent_class = NULL;
static BalaStatementIface * bala_for_statement_bala_statement_parent_iface = NULL;

static void bala_for_statement_real_accept (BalaCodeNode* base,
                                     BalaCodeVisitor* visitor);
static void bala_for_statement_real_accept_children (BalaCodeNode* base,
                                              BalaCodeVisitor* visitor);
static void bala_for_statement_real_replace_expression (BalaCodeNode* base,
                                                 BalaExpression* old_node,
                                                 BalaExpression* new_node);
static gboolean bala_for_statement_always_true (BalaForStatement* self,
                                         BalaExpression* condition);
static gboolean bala_for_statement_always_false (BalaForStatement* self,
                                          BalaExpression* condition);
static gboolean bala_for_statement_real_check (BalaCodeNode* base,
                                        BalaCodeContext* context);
static void bala_for_statement_finalize (BalaCodeNode * obj);
static GType bala_for_statement_get_type_once (void);

static inline gpointer
bala_for_statement_get_instance_private (BalaForStatement* self)
{
	return G_STRUCT_MEMBER_P (self, BalaForStatement_private_offset);
}

BalaExpression*
bala_for_statement_get_condition (BalaForStatement* self)
{
	BalaExpression* result;
	BalaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_condition;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

void
bala_for_statement_set_condition (BalaForStatement* self,
                                  BalaExpression* value)
{
	BalaExpression* _tmp0_;
	BalaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_condition);
	self->priv->_condition = _tmp0_;
	_tmp1_ = self->priv->_condition;
	if (_tmp1_ != NULL) {
		BalaExpression* _tmp2_;
		_tmp2_ = self->priv->_condition;
		bala_code_node_set_parent_node ((BalaCodeNode*) _tmp2_, (BalaCodeNode*) self);
	}
}

BalaBlock*
bala_for_statement_get_body (BalaForStatement* self)
{
	BalaBlock* result;
	BalaBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_body;
	result = _tmp0_;
	return result;
}

void
bala_for_statement_set_body (BalaForStatement* self,
                             BalaBlock* value)
{
	BalaBlock* _tmp0_;
	BalaBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_body);
	self->priv->_body = _tmp0_;
	_tmp1_ = self->priv->_body;
	bala_code_node_set_parent_node ((BalaCodeNode*) _tmp1_, (BalaCodeNode*) self);
}

/**
 * Creates a new for statement.
 *
 * @param condition        loop condition
 * @param body             loop body
 * @param source_reference reference to source code
 * @return                 newly created for statement
 */
BalaForStatement*
bala_for_statement_construct (GType object_type,
                              BalaExpression* condition,
                              BalaBlock* body,
                              BalaSourceReference* source_reference)
{
	BalaForStatement* self = NULL;
	g_return_val_if_fail (body != NULL, NULL);
	self = (BalaForStatement*) bala_code_node_construct (object_type);
	bala_for_statement_set_condition (self, condition);
	bala_for_statement_set_body (self, body);
	bala_code_node_set_source_reference ((BalaCodeNode*) self, source_reference);
	return self;
}

BalaForStatement*
bala_for_statement_new (BalaExpression* condition,
                        BalaBlock* body,
                        BalaSourceReference* source_reference)
{
	return bala_for_statement_construct (BALA_TYPE_FOR_STATEMENT, condition, body, source_reference);
}

/**
 * Appends the specified expression to the list of initializers.
 *
 * @param init an initializer expression
 */
void
bala_for_statement_add_initializer (BalaForStatement* self,
                                    BalaExpression* init)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (init != NULL);
	bala_code_node_set_parent_node ((BalaCodeNode*) init, (BalaCodeNode*) self);
	_tmp0_ = self->priv->initializer;
	bala_collection_add ((BalaCollection*) _tmp0_, init);
}

/**
 * Returns the list of initializers.
 *
 * @return initializer list
 */
BalaList*
bala_for_statement_get_initializer (BalaForStatement* self)
{
	BalaList* _tmp0_;
	BalaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->initializer;
	result = _tmp0_;
	return result;
}

/**
 * Appends the specified expression to the iterator.
 *
 * @param iter an iterator expression
 */
void
bala_for_statement_add_iterator (BalaForStatement* self,
                                 BalaExpression* iter)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (iter != NULL);
	bala_code_node_set_parent_node ((BalaCodeNode*) iter, (BalaCodeNode*) self);
	_tmp0_ = self->priv->iterator;
	bala_collection_add ((BalaCollection*) _tmp0_, iter);
}

/**
 * Returns the iterator.
 *
 * @return iterator
 */
BalaList*
bala_for_statement_get_iterator (BalaForStatement* self)
{
	BalaList* _tmp0_;
	BalaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->iterator;
	result = _tmp0_;
	return result;
}

static void
bala_for_statement_real_accept (BalaCodeNode* base,
                                BalaCodeVisitor* visitor)
{
	BalaForStatement * self;
	self = (BalaForStatement*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_for_statement (visitor, self);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static void
bala_for_statement_real_accept_children (BalaCodeNode* base,
                                         BalaCodeVisitor* visitor)
{
	BalaForStatement * self;
	BalaExpression* _tmp11_;
	BalaExpression* _tmp12_;
	BalaBlock* _tmp28_;
	BalaBlock* _tmp29_;
	self = (BalaForStatement*) base;
	g_return_if_fail (visitor != NULL);
	{
		BalaList* _init_expr_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _init_expr_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _init_expr_index = 0;
		_tmp0_ = self->priv->initializer;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_init_expr_list = _tmp1_;
		_tmp2_ = _init_expr_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_init_expr_size = _tmp4_;
		_init_expr_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaExpression* init_expr = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaExpression* _tmp9_;
			BalaExpression* _tmp10_;
			_init_expr_index = _init_expr_index + 1;
			_tmp5_ = _init_expr_index;
			_tmp6_ = _init_expr_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _init_expr_list;
			_tmp8_ = bala_list_get (_tmp7_, _init_expr_index);
			init_expr = (BalaExpression*) _tmp8_;
			_tmp9_ = init_expr;
			bala_code_node_accept ((BalaCodeNode*) _tmp9_, visitor);
			_tmp10_ = init_expr;
			bala_code_visitor_visit_end_full_expression (visitor, _tmp10_);
			_bala_code_node_unref0 (init_expr);
		}
		_bala_iterable_unref0 (_init_expr_list);
	}
	_tmp11_ = bala_for_statement_get_condition (self);
	_tmp12_ = _tmp11_;
	if (_tmp12_ != NULL) {
		BalaExpression* _tmp13_;
		BalaExpression* _tmp14_;
		BalaExpression* _tmp15_;
		BalaExpression* _tmp16_;
		_tmp13_ = bala_for_statement_get_condition (self);
		_tmp14_ = _tmp13_;
		bala_code_node_accept ((BalaCodeNode*) _tmp14_, visitor);
		_tmp15_ = bala_for_statement_get_condition (self);
		_tmp16_ = _tmp15_;
		bala_code_visitor_visit_end_full_expression (visitor, _tmp16_);
	}
	{
		BalaList* _it_expr_list = NULL;
		BalaList* _tmp17_;
		BalaList* _tmp18_;
		gint _it_expr_size = 0;
		BalaList* _tmp19_;
		gint _tmp20_;
		gint _tmp21_;
		gint _it_expr_index = 0;
		_tmp17_ = self->priv->iterator;
		_tmp18_ = _bala_iterable_ref0 (_tmp17_);
		_it_expr_list = _tmp18_;
		_tmp19_ = _it_expr_list;
		_tmp20_ = bala_collection_get_size ((BalaCollection*) _tmp19_);
		_tmp21_ = _tmp20_;
		_it_expr_size = _tmp21_;
		_it_expr_index = -1;
		while (TRUE) {
			gint _tmp22_;
			gint _tmp23_;
			BalaExpression* it_expr = NULL;
			BalaList* _tmp24_;
			gpointer _tmp25_;
			BalaExpression* _tmp26_;
			BalaExpression* _tmp27_;
			_it_expr_index = _it_expr_index + 1;
			_tmp22_ = _it_expr_index;
			_tmp23_ = _it_expr_size;
			if (!(_tmp22_ < _tmp23_)) {
				break;
			}
			_tmp24_ = _it_expr_list;
			_tmp25_ = bala_list_get (_tmp24_, _it_expr_index);
			it_expr = (BalaExpression*) _tmp25_;
			_tmp26_ = it_expr;
			bala_code_node_accept ((BalaCodeNode*) _tmp26_, visitor);
			_tmp27_ = it_expr;
			bala_code_visitor_visit_end_full_expression (visitor, _tmp27_);
			_bala_code_node_unref0 (it_expr);
		}
		_bala_iterable_unref0 (_it_expr_list);
	}
	_tmp28_ = bala_for_statement_get_body (self);
	_tmp29_ = _tmp28_;
	bala_code_node_accept ((BalaCodeNode*) _tmp29_, visitor);
}

static void
bala_for_statement_real_replace_expression (BalaCodeNode* base,
                                            BalaExpression* old_node,
                                            BalaExpression* new_node)
{
	BalaForStatement * self;
	BalaExpression* _tmp0_;
	BalaExpression* _tmp1_;
	self = (BalaForStatement*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = bala_for_statement_get_condition (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		bala_for_statement_set_condition (self, new_node);
	}
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp2_ = FALSE;
			_tmp2_ = TRUE;
			while (TRUE) {
				BalaList* _tmp4_;
				gint _tmp5_;
				gint _tmp6_;
				BalaList* _tmp7_;
				gpointer _tmp8_;
				BalaExpression* _tmp9_;
				gboolean _tmp10_;
				if (!_tmp2_) {
					gint _tmp3_;
					_tmp3_ = i;
					i = _tmp3_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp4_ = self->priv->initializer;
				_tmp5_ = bala_collection_get_size ((BalaCollection*) _tmp4_);
				_tmp6_ = _tmp5_;
				if (!(i < _tmp6_)) {
					break;
				}
				_tmp7_ = self->priv->initializer;
				_tmp8_ = bala_list_get (_tmp7_, i);
				_tmp9_ = (BalaExpression*) _tmp8_;
				_tmp10_ = _tmp9_ == old_node;
				_bala_code_node_unref0 (_tmp9_);
				if (_tmp10_) {
					BalaList* _tmp11_;
					_tmp11_ = self->priv->initializer;
					bala_list_set (_tmp11_, i, new_node);
					bala_code_node_set_parent_node ((BalaCodeNode*) new_node, (BalaCodeNode*) self);
				}
			}
		}
	}
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp12_ = FALSE;
			_tmp12_ = TRUE;
			while (TRUE) {
				BalaList* _tmp14_;
				gint _tmp15_;
				gint _tmp16_;
				BalaList* _tmp17_;
				gpointer _tmp18_;
				BalaExpression* _tmp19_;
				gboolean _tmp20_;
				if (!_tmp12_) {
					gint _tmp13_;
					_tmp13_ = i;
					i = _tmp13_ + 1;
				}
				_tmp12_ = FALSE;
				_tmp14_ = self->priv->iterator;
				_tmp15_ = bala_collection_get_size ((BalaCollection*) _tmp14_);
				_tmp16_ = _tmp15_;
				if (!(i < _tmp16_)) {
					break;
				}
				_tmp17_ = self->priv->iterator;
				_tmp18_ = bala_list_get (_tmp17_, i);
				_tmp19_ = (BalaExpression*) _tmp18_;
				_tmp20_ = _tmp19_ == old_node;
				_bala_code_node_unref0 (_tmp19_);
				if (_tmp20_) {
					BalaList* _tmp21_;
					_tmp21_ = self->priv->iterator;
					bala_list_set (_tmp21_, i, new_node);
					bala_code_node_set_parent_node ((BalaCodeNode*) new_node, (BalaCodeNode*) self);
				}
			}
		}
	}
}

static gboolean
bala_for_statement_always_true (BalaForStatement* self,
                                BalaExpression* condition)
{
	BalaBooleanLiteral* literal = NULL;
	gboolean _tmp0_ = FALSE;
	BalaBooleanLiteral* _tmp1_;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (condition != NULL, FALSE);
	literal = BALA_IS_BOOLEAN_LITERAL (condition) ? ((BalaBooleanLiteral*) condition) : NULL;
	_tmp1_ = literal;
	if (_tmp1_ != NULL) {
		BalaBooleanLiteral* _tmp2_;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp2_ = literal;
		_tmp3_ = bala_boolean_literal_get_value (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = _tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static gboolean
bala_for_statement_always_false (BalaForStatement* self,
                                 BalaExpression* condition)
{
	BalaBooleanLiteral* literal = NULL;
	gboolean _tmp0_ = FALSE;
	BalaBooleanLiteral* _tmp1_;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (condition != NULL, FALSE);
	literal = BALA_IS_BOOLEAN_LITERAL (condition) ? ((BalaBooleanLiteral*) condition) : NULL;
	_tmp1_ = literal;
	if (_tmp1_ != NULL) {
		BalaBooleanLiteral* _tmp2_;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp2_ = literal;
		_tmp3_ = bala_boolean_literal_get_value (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = !_tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static gboolean
bala_for_statement_real_check (BalaCodeNode* base,
                               BalaCodeContext* context)
{
	BalaForStatement * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	BalaBlock* block = NULL;
	BalaSourceReference* _tmp4_;
	BalaSourceReference* _tmp5_;
	BalaBlock* _tmp6_;
	gboolean _tmp23_ = FALSE;
	BalaExpression* _tmp24_;
	BalaExpression* _tmp25_;
	BalaLocalVariable* first_local = NULL;
	BalaSemanticAnalyzer* _tmp67_;
	BalaSemanticAnalyzer* _tmp68_;
	BalaDataType* _tmp69_;
	BalaDataType* _tmp70_;
	BalaDataType* _tmp71_;
	gchar* _tmp72_;
	gchar* _tmp73_;
	BalaSourceReference* _tmp74_;
	BalaSourceReference* _tmp75_;
	BalaBooleanLiteral* _tmp76_;
	BalaBooleanLiteral* _tmp77_;
	BalaSourceReference* _tmp78_;
	BalaSourceReference* _tmp79_;
	BalaLocalVariable* _tmp80_;
	BalaLocalVariable* _tmp81_;
	BalaBlock* _tmp82_;
	BalaLocalVariable* _tmp83_;
	BalaSourceReference* _tmp84_;
	BalaSourceReference* _tmp85_;
	BalaDeclarationStatement* _tmp86_;
	BalaDeclarationStatement* _tmp87_;
	BalaBlock* iterator_block = NULL;
	BalaSourceReference* _tmp88_;
	BalaSourceReference* _tmp89_;
	BalaBlock* _tmp90_;
	BalaIfStatement* first_if = NULL;
	BalaLocalVariable* _tmp107_;
	const gchar* _tmp108_;
	const gchar* _tmp109_;
	BalaSourceReference* _tmp110_;
	BalaSourceReference* _tmp111_;
	BalaMemberAccess* _tmp112_;
	BalaMemberAccess* _tmp113_;
	BalaSourceReference* _tmp114_;
	BalaSourceReference* _tmp115_;
	BalaUnaryExpression* _tmp116_;
	BalaUnaryExpression* _tmp117_;
	BalaBlock* _tmp118_;
	BalaSourceReference* _tmp119_;
	BalaSourceReference* _tmp120_;
	BalaIfStatement* _tmp121_;
	BalaIfStatement* _tmp122_;
	BalaBlock* _tmp123_;
	BalaBlock* _tmp124_;
	BalaIfStatement* _tmp125_;
	BalaBlock* _tmp126_;
	BalaBlock* _tmp127_;
	BalaLocalVariable* _tmp128_;
	const gchar* _tmp129_;
	const gchar* _tmp130_;
	BalaSourceReference* _tmp131_;
	BalaSourceReference* _tmp132_;
	BalaMemberAccess* _tmp133_;
	BalaMemberAccess* _tmp134_;
	BalaSourceReference* _tmp135_;
	BalaSourceReference* _tmp136_;
	BalaBooleanLiteral* _tmp137_;
	BalaBooleanLiteral* _tmp138_;
	BalaSourceReference* _tmp139_;
	BalaSourceReference* _tmp140_;
	BalaAssignment* _tmp141_;
	BalaAssignment* _tmp142_;
	BalaSourceReference* _tmp143_;
	BalaSourceReference* _tmp144_;
	BalaExpressionStatement* _tmp145_;
	BalaExpressionStatement* _tmp146_;
	BalaBlock* _tmp147_;
	BalaBlock* _tmp148_;
	BalaBlock* _tmp149_;
	BalaSourceReference* _tmp150_;
	BalaSourceReference* _tmp151_;
	BalaLoop* _tmp152_;
	BalaLoop* _tmp153_;
	BalaBlock* parent_block = NULL;
	BalaCodeNode* _tmp154_;
	BalaCodeNode* _tmp155_;
	BalaBlock* _tmp156_;
	BalaBlock* _tmp157_;
	BalaBlock* _tmp158_;
	gboolean _tmp159_;
	gboolean _tmp160_;
	gboolean result = FALSE;
	self = (BalaForStatement*) base;
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
	_tmp4_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp5_ = _tmp4_;
	_tmp6_ = bala_block_new (_tmp5_);
	block = _tmp6_;
	{
		BalaList* _init_expr_list = NULL;
		BalaList* _tmp7_;
		BalaList* _tmp8_;
		gint _init_expr_size = 0;
		BalaList* _tmp9_;
		gint _tmp10_;
		gint _tmp11_;
		gint _init_expr_index = 0;
		_tmp7_ = self->priv->initializer;
		_tmp8_ = _bala_iterable_ref0 (_tmp7_);
		_init_expr_list = _tmp8_;
		_tmp9_ = _init_expr_list;
		_tmp10_ = bala_collection_get_size ((BalaCollection*) _tmp9_);
		_tmp11_ = _tmp10_;
		_init_expr_size = _tmp11_;
		_init_expr_index = -1;
		while (TRUE) {
			gint _tmp12_;
			gint _tmp13_;
			BalaExpression* init_expr = NULL;
			BalaList* _tmp14_;
			gpointer _tmp15_;
			BalaBlock* _tmp16_;
			BalaExpression* _tmp17_;
			BalaExpression* _tmp18_;
			BalaSourceReference* _tmp19_;
			BalaSourceReference* _tmp20_;
			BalaExpressionStatement* _tmp21_;
			BalaExpressionStatement* _tmp22_;
			_init_expr_index = _init_expr_index + 1;
			_tmp12_ = _init_expr_index;
			_tmp13_ = _init_expr_size;
			if (!(_tmp12_ < _tmp13_)) {
				break;
			}
			_tmp14_ = _init_expr_list;
			_tmp15_ = bala_list_get (_tmp14_, _init_expr_index);
			init_expr = (BalaExpression*) _tmp15_;
			_tmp16_ = block;
			_tmp17_ = init_expr;
			_tmp18_ = init_expr;
			_tmp19_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp18_);
			_tmp20_ = _tmp19_;
			_tmp21_ = bala_expression_statement_new (_tmp17_, _tmp20_);
			_tmp22_ = _tmp21_;
			bala_block_add_statement (_tmp16_, (BalaStatement*) _tmp22_);
			_bala_code_node_unref0 (_tmp22_);
			_bala_code_node_unref0 (init_expr);
		}
		_bala_iterable_unref0 (_init_expr_list);
	}
	_tmp24_ = bala_for_statement_get_condition (self);
	_tmp25_ = _tmp24_;
	if (_tmp25_ == NULL) {
		_tmp23_ = TRUE;
	} else {
		BalaExpression* _tmp26_;
		BalaExpression* _tmp27_;
		_tmp26_ = bala_for_statement_get_condition (self);
		_tmp27_ = _tmp26_;
		_tmp23_ = bala_for_statement_always_true (self, _tmp27_);
	}
	if (_tmp23_) {
	} else {
		BalaExpression* _tmp28_;
		BalaExpression* _tmp29_;
		_tmp28_ = bala_for_statement_get_condition (self);
		_tmp29_ = _tmp28_;
		if (bala_for_statement_always_false (self, _tmp29_)) {
			BalaBlock* _tmp30_;
			BalaBlock* _tmp31_;
			BalaExpression* _tmp32_;
			BalaExpression* _tmp33_;
			BalaSourceReference* _tmp34_;
			BalaSourceReference* _tmp35_;
			BalaBreakStatement* _tmp36_;
			BalaBreakStatement* _tmp37_;
			_tmp30_ = bala_for_statement_get_body (self);
			_tmp31_ = _tmp30_;
			_tmp32_ = bala_for_statement_get_condition (self);
			_tmp33_ = _tmp32_;
			_tmp34_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp33_);
			_tmp35_ = _tmp34_;
			_tmp36_ = bala_break_statement_new (_tmp35_);
			_tmp37_ = _tmp36_;
			bala_block_insert_statement (_tmp31_, 0, (BalaStatement*) _tmp37_);
			_bala_code_node_unref0 (_tmp37_);
		} else {
			BalaUnaryExpression* if_condition = NULL;
			BalaExpression* _tmp38_;
			BalaExpression* _tmp39_;
			BalaExpression* _tmp40_;
			BalaExpression* _tmp41_;
			BalaSourceReference* _tmp42_;
			BalaSourceReference* _tmp43_;
			BalaUnaryExpression* _tmp44_;
			BalaBlock* true_block = NULL;
			BalaExpression* _tmp45_;
			BalaExpression* _tmp46_;
			BalaSourceReference* _tmp47_;
			BalaSourceReference* _tmp48_;
			BalaBlock* _tmp49_;
			BalaBlock* _tmp50_;
			BalaExpression* _tmp51_;
			BalaExpression* _tmp52_;
			BalaSourceReference* _tmp53_;
			BalaSourceReference* _tmp54_;
			BalaBreakStatement* _tmp55_;
			BalaBreakStatement* _tmp56_;
			BalaIfStatement* if_stmt = NULL;
			BalaUnaryExpression* _tmp57_;
			BalaBlock* _tmp58_;
			BalaExpression* _tmp59_;
			BalaExpression* _tmp60_;
			BalaSourceReference* _tmp61_;
			BalaSourceReference* _tmp62_;
			BalaIfStatement* _tmp63_;
			BalaBlock* _tmp64_;
			BalaBlock* _tmp65_;
			BalaIfStatement* _tmp66_;
			_tmp38_ = bala_for_statement_get_condition (self);
			_tmp39_ = _tmp38_;
			_tmp40_ = bala_for_statement_get_condition (self);
			_tmp41_ = _tmp40_;
			_tmp42_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp41_);
			_tmp43_ = _tmp42_;
			_tmp44_ = bala_unary_expression_new (BALA_UNARY_OPERATOR_LOGICAL_NEGATION, _tmp39_, _tmp43_);
			if_condition = _tmp44_;
			_tmp45_ = bala_for_statement_get_condition (self);
			_tmp46_ = _tmp45_;
			_tmp47_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp46_);
			_tmp48_ = _tmp47_;
			_tmp49_ = bala_block_new (_tmp48_);
			true_block = _tmp49_;
			_tmp50_ = true_block;
			_tmp51_ = bala_for_statement_get_condition (self);
			_tmp52_ = _tmp51_;
			_tmp53_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp52_);
			_tmp54_ = _tmp53_;
			_tmp55_ = bala_break_statement_new (_tmp54_);
			_tmp56_ = _tmp55_;
			bala_block_add_statement (_tmp50_, (BalaStatement*) _tmp56_);
			_bala_code_node_unref0 (_tmp56_);
			_tmp57_ = if_condition;
			_tmp58_ = true_block;
			_tmp59_ = bala_for_statement_get_condition (self);
			_tmp60_ = _tmp59_;
			_tmp61_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp60_);
			_tmp62_ = _tmp61_;
			_tmp63_ = bala_if_statement_new ((BalaExpression*) _tmp57_, _tmp58_, NULL, _tmp62_);
			if_stmt = _tmp63_;
			_tmp64_ = bala_for_statement_get_body (self);
			_tmp65_ = _tmp64_;
			_tmp66_ = if_stmt;
			bala_block_insert_statement (_tmp65_, 0, (BalaStatement*) _tmp66_);
			_bala_code_node_unref0 (if_stmt);
			_bala_code_node_unref0 (true_block);
			_bala_code_node_unref0 (if_condition);
		}
	}
	_tmp67_ = bala_code_context_get_analyzer (context);
	_tmp68_ = _tmp67_;
	_tmp69_ = _tmp68_->bool_type;
	_tmp70_ = bala_data_type_copy (_tmp69_);
	_tmp71_ = _tmp70_;
	_tmp72_ = bala_code_node_get_temp_name ();
	_tmp73_ = _tmp72_;
	_tmp74_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp75_ = _tmp74_;
	_tmp76_ = bala_boolean_literal_new (TRUE, _tmp75_);
	_tmp77_ = _tmp76_;
	_tmp78_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp79_ = _tmp78_;
	_tmp80_ = bala_local_variable_new (_tmp71_, _tmp73_, (BalaExpression*) _tmp77_, _tmp79_);
	_tmp81_ = _tmp80_;
	_bala_code_node_unref0 (_tmp77_);
	_g_free0 (_tmp73_);
	_bala_code_node_unref0 (_tmp71_);
	first_local = _tmp81_;
	_tmp82_ = block;
	_tmp83_ = first_local;
	_tmp84_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp85_ = _tmp84_;
	_tmp86_ = bala_declaration_statement_new ((BalaSymbol*) _tmp83_, _tmp85_);
	_tmp87_ = _tmp86_;
	bala_block_add_statement (_tmp82_, (BalaStatement*) _tmp87_);
	_bala_code_node_unref0 (_tmp87_);
	_tmp88_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp89_ = _tmp88_;
	_tmp90_ = bala_block_new (_tmp89_);
	iterator_block = _tmp90_;
	{
		BalaList* _it_expr_list = NULL;
		BalaList* _tmp91_;
		BalaList* _tmp92_;
		gint _it_expr_size = 0;
		BalaList* _tmp93_;
		gint _tmp94_;
		gint _tmp95_;
		gint _it_expr_index = 0;
		_tmp91_ = self->priv->iterator;
		_tmp92_ = _bala_iterable_ref0 (_tmp91_);
		_it_expr_list = _tmp92_;
		_tmp93_ = _it_expr_list;
		_tmp94_ = bala_collection_get_size ((BalaCollection*) _tmp93_);
		_tmp95_ = _tmp94_;
		_it_expr_size = _tmp95_;
		_it_expr_index = -1;
		while (TRUE) {
			gint _tmp96_;
			gint _tmp97_;
			BalaExpression* it_expr = NULL;
			BalaList* _tmp98_;
			gpointer _tmp99_;
			BalaBlock* _tmp100_;
			BalaExpression* _tmp101_;
			BalaExpression* _tmp102_;
			BalaSourceReference* _tmp103_;
			BalaSourceReference* _tmp104_;
			BalaExpressionStatement* _tmp105_;
			BalaExpressionStatement* _tmp106_;
			_it_expr_index = _it_expr_index + 1;
			_tmp96_ = _it_expr_index;
			_tmp97_ = _it_expr_size;
			if (!(_tmp96_ < _tmp97_)) {
				break;
			}
			_tmp98_ = _it_expr_list;
			_tmp99_ = bala_list_get (_tmp98_, _it_expr_index);
			it_expr = (BalaExpression*) _tmp99_;
			_tmp100_ = iterator_block;
			_tmp101_ = it_expr;
			_tmp102_ = it_expr;
			_tmp103_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp102_);
			_tmp104_ = _tmp103_;
			_tmp105_ = bala_expression_statement_new (_tmp101_, _tmp104_);
			_tmp106_ = _tmp105_;
			bala_block_add_statement (_tmp100_, (BalaStatement*) _tmp106_);
			_bala_code_node_unref0 (_tmp106_);
			_bala_code_node_unref0 (it_expr);
		}
		_bala_iterable_unref0 (_it_expr_list);
	}
	_tmp107_ = first_local;
	_tmp108_ = bala_symbol_get_name ((BalaSymbol*) _tmp107_);
	_tmp109_ = _tmp108_;
	_tmp110_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp111_ = _tmp110_;
	_tmp112_ = bala_member_access_new_simple (_tmp109_, _tmp111_);
	_tmp113_ = _tmp112_;
	_tmp114_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp115_ = _tmp114_;
	_tmp116_ = bala_unary_expression_new (BALA_UNARY_OPERATOR_LOGICAL_NEGATION, (BalaExpression*) _tmp113_, _tmp115_);
	_tmp117_ = _tmp116_;
	_tmp118_ = iterator_block;
	_tmp119_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp120_ = _tmp119_;
	_tmp121_ = bala_if_statement_new ((BalaExpression*) _tmp117_, _tmp118_, NULL, _tmp120_);
	_tmp122_ = _tmp121_;
	_bala_code_node_unref0 (_tmp117_);
	_bala_code_node_unref0 (_tmp113_);
	first_if = _tmp122_;
	_tmp123_ = bala_for_statement_get_body (self);
	_tmp124_ = _tmp123_;
	_tmp125_ = first_if;
	bala_block_insert_statement (_tmp124_, 0, (BalaStatement*) _tmp125_);
	_tmp126_ = bala_for_statement_get_body (self);
	_tmp127_ = _tmp126_;
	_tmp128_ = first_local;
	_tmp129_ = bala_symbol_get_name ((BalaSymbol*) _tmp128_);
	_tmp130_ = _tmp129_;
	_tmp131_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp132_ = _tmp131_;
	_tmp133_ = bala_member_access_new_simple (_tmp130_, _tmp132_);
	_tmp134_ = _tmp133_;
	_tmp135_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp136_ = _tmp135_;
	_tmp137_ = bala_boolean_literal_new (FALSE, _tmp136_);
	_tmp138_ = _tmp137_;
	_tmp139_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp140_ = _tmp139_;
	_tmp141_ = bala_assignment_new ((BalaExpression*) _tmp134_, (BalaExpression*) _tmp138_, BALA_ASSIGNMENT_OPERATOR_SIMPLE, _tmp140_);
	_tmp142_ = _tmp141_;
	_tmp143_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp144_ = _tmp143_;
	_tmp145_ = bala_expression_statement_new ((BalaExpression*) _tmp142_, _tmp144_);
	_tmp146_ = _tmp145_;
	bala_block_insert_statement (_tmp127_, 1, (BalaStatement*) _tmp146_);
	_bala_code_node_unref0 (_tmp146_);
	_bala_code_node_unref0 (_tmp142_);
	_bala_code_node_unref0 (_tmp138_);
	_bala_code_node_unref0 (_tmp134_);
	_tmp147_ = block;
	_tmp148_ = bala_for_statement_get_body (self);
	_tmp149_ = _tmp148_;
	_tmp150_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
	_tmp151_ = _tmp150_;
	_tmp152_ = bala_loop_new (_tmp149_, _tmp151_);
	_tmp153_ = _tmp152_;
	bala_block_add_statement (_tmp147_, (BalaStatement*) _tmp153_);
	_bala_code_node_unref0 (_tmp153_);
	_tmp154_ = bala_code_node_get_parent_node ((BalaCodeNode*) self);
	_tmp155_ = _tmp154_;
	parent_block = G_TYPE_CHECK_INSTANCE_CAST (_tmp155_, BALA_TYPE_BLOCK, BalaBlock);
	_tmp156_ = parent_block;
	_tmp157_ = block;
	bala_block_replace_statement (_tmp156_, (BalaStatement*) self, (BalaStatement*) _tmp157_);
	_tmp158_ = block;
	if (!bala_code_node_check ((BalaCodeNode*) _tmp158_, context)) {
		bala_code_node_set_error ((BalaCodeNode*) self, TRUE);
	}
	_tmp159_ = bala_code_node_get_error ((BalaCodeNode*) self);
	_tmp160_ = _tmp159_;
	result = !_tmp160_;
	_bala_code_node_unref0 (first_if);
	_bala_code_node_unref0 (iterator_block);
	_bala_code_node_unref0 (first_local);
	_bala_code_node_unref0 (block);
	return result;
}

static void
bala_for_statement_class_init (BalaForStatementClass * klass,
                               gpointer klass_data)
{
	bala_for_statement_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_for_statement_finalize;
	g_type_class_adjust_private_offset (klass, &BalaForStatement_private_offset);
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_for_statement_real_accept;
	((BalaCodeNodeClass *) klass)->accept_children = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_for_statement_real_accept_children;
	((BalaCodeNodeClass *) klass)->replace_expression = (void (*) (BalaCodeNode*, BalaExpression*, BalaExpression*)) bala_for_statement_real_replace_expression;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_for_statement_real_check;
}

static void
bala_for_statement_bala_statement_interface_init (BalaStatementIface * iface,
                                                  gpointer iface_data)
{
	bala_for_statement_bala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
bala_for_statement_instance_init (BalaForStatement * self,
                                  gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	GEqualFunc _tmp2_;
	BalaArrayList* _tmp3_;
	self->priv = bala_for_statement_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_EXPRESSION, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp0_);
	self->priv->initializer = (BalaList*) _tmp1_;
	_tmp2_ = g_direct_equal;
	_tmp3_ = bala_array_list_new (BALA_TYPE_EXPRESSION, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp2_);
	self->priv->iterator = (BalaList*) _tmp3_;
}

static void
bala_for_statement_finalize (BalaCodeNode * obj)
{
	BalaForStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_FOR_STATEMENT, BalaForStatement);
	_bala_iterable_unref0 (self->priv->initializer);
	_bala_iterable_unref0 (self->priv->iterator);
	_bala_code_node_unref0 (self->priv->_condition);
	_bala_code_node_unref0 (self->priv->_body);
	BALA_CODE_NODE_CLASS (bala_for_statement_parent_class)->finalize (obj);
}

/**
 * Represents a for iteration statement in the source code.
 */
static GType
bala_for_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaForStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_for_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaForStatement), 0, (GInstanceInitFunc) bala_for_statement_instance_init, NULL };
	static const GInterfaceInfo bala_statement_info = { (GInterfaceInitFunc) bala_for_statement_bala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType bala_for_statement_type_id;
	bala_for_statement_type_id = g_type_register_static (BALA_TYPE_CODE_NODE, "BalaForStatement", &g_define_type_info, 0);
	g_type_add_interface_static (bala_for_statement_type_id, BALA_TYPE_STATEMENT, &bala_statement_info);
	BalaForStatement_private_offset = g_type_add_instance_private (bala_for_statement_type_id, sizeof (BalaForStatementPrivate));
	return bala_for_statement_type_id;
}

GType
bala_for_statement_get_type (void)
{
	static volatile gsize bala_for_statement_type_id__volatile = 0;
	if (g_once_init_enter (&bala_for_statement_type_id__volatile)) {
		GType bala_for_statement_type_id;
		bala_for_statement_type_id = bala_for_statement_get_type_once ();
		g_once_init_leave (&bala_for_statement_type_id__volatile, bala_for_statement_type_id);
	}
	return bala_for_statement_type_id__volatile;
}

