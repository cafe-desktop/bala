/* valadostatement.c generated by valac, the Vala compiler
 * generated from valadostatement.vala, do not modify */

/* valadostatement.vala
 *
 * Copyright (C) 2006-2009  Jürg Billeter
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

#include "vala.h"
#include <glib.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaDoStatementPrivate {
	ValaExpression* _condition;
	ValaBlock* _body;
};

static gint ValaDoStatement_private_offset;
static gpointer vala_do_statement_parent_class = NULL;
static ValaStatementIface * vala_do_statement_vala_statement_parent_iface = NULL;

static void vala_do_statement_real_accept (ValaCodeNode* base,
                                    ValaCodeVisitor* visitor);
static void vala_do_statement_real_accept_children (ValaCodeNode* base,
                                             ValaCodeVisitor* visitor);
static gboolean vala_do_statement_always_true (ValaDoStatement* self,
                                        ValaExpression* condition);
static void vala_do_statement_real_replace_expression (ValaCodeNode* base,
                                                ValaExpression* old_node,
                                                ValaExpression* new_node);
static gboolean vala_do_statement_real_check (ValaCodeNode* base,
                                       ValaCodeContext* context);
static void vala_do_statement_finalize (ValaCodeNode * obj);
static GType vala_do_statement_get_type_once (void);

static inline gpointer
vala_do_statement_get_instance_private (ValaDoStatement* self)
{
	return G_STRUCT_MEMBER_P (self, ValaDoStatement_private_offset);
}

ValaBlock*
vala_do_statement_get_body (ValaDoStatement* self)
{
	ValaBlock* result;
	ValaBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_body;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_do_statement_set_body (ValaDoStatement* self,
                            ValaBlock* value)
{
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_body);
	self->priv->_body = _tmp0_;
	_tmp1_ = self->priv->_body;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

ValaExpression*
vala_do_statement_get_condition (ValaDoStatement* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_condition;
	result = _tmp0_;
	return result;
}

void
vala_do_statement_set_condition (ValaDoStatement* self,
                                 ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_condition);
	self->priv->_condition = _tmp0_;
	_tmp1_ = self->priv->_condition;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

/**
 * Creates a new do statement.
 *
 * @param body              loop body
 * @param condition         loop condition
 * @param source_reference  reference to source code
 * @return                  newly created do statement
 */
ValaDoStatement*
vala_do_statement_construct (GType object_type,
                             ValaBlock* body,
                             ValaExpression* condition,
                             ValaSourceReference* source_reference)
{
	ValaDoStatement* self = NULL;
	g_return_val_if_fail (body != NULL, NULL);
	g_return_val_if_fail (condition != NULL, NULL);
	self = (ValaDoStatement*) vala_code_node_construct (object_type);
	vala_do_statement_set_condition (self, condition);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	vala_do_statement_set_body (self, body);
	return self;
}

ValaDoStatement*
vala_do_statement_new (ValaBlock* body,
                       ValaExpression* condition,
                       ValaSourceReference* source_reference)
{
	return vala_do_statement_construct (VALA_TYPE_DO_STATEMENT, body, condition, source_reference);
}

static void
vala_do_statement_real_accept (ValaCodeNode* base,
                               ValaCodeVisitor* visitor)
{
	ValaDoStatement * self;
	self = (ValaDoStatement*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_do_statement (visitor, self);
}

static void
vala_do_statement_real_accept_children (ValaCodeNode* base,
                                        ValaCodeVisitor* visitor)
{
	ValaDoStatement * self;
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	ValaExpression* _tmp2_;
	ValaExpression* _tmp3_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	self = (ValaDoStatement*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_do_statement_get_body (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
	_tmp2_ = vala_do_statement_get_condition (self);
	_tmp3_ = _tmp2_;
	vala_code_node_accept ((ValaCodeNode*) _tmp3_, visitor);
	_tmp4_ = vala_do_statement_get_condition (self);
	_tmp5_ = _tmp4_;
	vala_code_visitor_visit_end_full_expression (visitor, _tmp5_);
}

static gboolean
vala_do_statement_always_true (ValaDoStatement* self,
                               ValaExpression* condition)
{
	ValaBooleanLiteral* literal = NULL;
	gboolean _tmp0_ = FALSE;
	ValaBooleanLiteral* _tmp1_;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (condition != NULL, FALSE);
	literal = VALA_IS_BOOLEAN_LITERAL (condition) ? ((ValaBooleanLiteral*) condition) : NULL;
	_tmp1_ = literal;
	if (_tmp1_ != NULL) {
		ValaBooleanLiteral* _tmp2_;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp2_ = literal;
		_tmp3_ = vala_boolean_literal_get_value (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = _tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static void
vala_do_statement_real_replace_expression (ValaCodeNode* base,
                                           ValaExpression* old_node,
                                           ValaExpression* new_node)
{
	ValaDoStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaDoStatement*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_do_statement_get_condition (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_do_statement_set_condition (self, new_node);
	}
}

static gboolean
vala_do_statement_real_check (ValaCodeNode* base,
                              ValaCodeContext* context)
{
	ValaDoStatement * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	ValaBlock* block = NULL;
	ValaSourceReference* _tmp18_;
	ValaSourceReference* _tmp19_;
	ValaBlock* _tmp20_;
	ValaLocalVariable* first_local = NULL;
	ValaSemanticAnalyzer* _tmp21_;
	ValaSemanticAnalyzer* _tmp22_;
	ValaDataType* _tmp23_;
	ValaDataType* _tmp24_;
	ValaDataType* _tmp25_;
	gchar* _tmp26_;
	gchar* _tmp27_;
	ValaSourceReference* _tmp28_;
	ValaSourceReference* _tmp29_;
	ValaBooleanLiteral* _tmp30_;
	ValaBooleanLiteral* _tmp31_;
	ValaSourceReference* _tmp32_;
	ValaSourceReference* _tmp33_;
	ValaLocalVariable* _tmp34_;
	ValaLocalVariable* _tmp35_;
	ValaBlock* _tmp36_;
	ValaLocalVariable* _tmp37_;
	ValaSourceReference* _tmp38_;
	ValaSourceReference* _tmp39_;
	ValaDeclarationStatement* _tmp40_;
	ValaDeclarationStatement* _tmp41_;
	ValaUnaryExpression* if_condition = NULL;
	ValaExpression* _tmp42_;
	ValaExpression* _tmp43_;
	ValaExpression* _tmp44_;
	ValaExpression* _tmp45_;
	ValaSourceReference* _tmp46_;
	ValaSourceReference* _tmp47_;
	ValaUnaryExpression* _tmp48_;
	ValaBlock* true_block = NULL;
	ValaExpression* _tmp49_;
	ValaExpression* _tmp50_;
	ValaSourceReference* _tmp51_;
	ValaSourceReference* _tmp52_;
	ValaBlock* _tmp53_;
	ValaBlock* _tmp54_;
	ValaExpression* _tmp55_;
	ValaExpression* _tmp56_;
	ValaSourceReference* _tmp57_;
	ValaSourceReference* _tmp58_;
	ValaBreakStatement* _tmp59_;
	ValaBreakStatement* _tmp60_;
	ValaIfStatement* if_stmt = NULL;
	ValaUnaryExpression* _tmp61_;
	ValaBlock* _tmp62_;
	ValaExpression* _tmp63_;
	ValaExpression* _tmp64_;
	ValaSourceReference* _tmp65_;
	ValaSourceReference* _tmp66_;
	ValaIfStatement* _tmp67_;
	ValaBlock* condition_block = NULL;
	ValaExpression* _tmp68_;
	ValaExpression* _tmp69_;
	ValaSourceReference* _tmp70_;
	ValaSourceReference* _tmp71_;
	ValaBlock* _tmp72_;
	ValaBlock* _tmp73_;
	ValaIfStatement* _tmp74_;
	ValaIfStatement* first_if = NULL;
	ValaLocalVariable* _tmp75_;
	const gchar* _tmp76_;
	const gchar* _tmp77_;
	ValaSourceReference* _tmp78_;
	ValaSourceReference* _tmp79_;
	ValaMemberAccess* _tmp80_;
	ValaMemberAccess* _tmp81_;
	ValaSourceReference* _tmp82_;
	ValaSourceReference* _tmp83_;
	ValaUnaryExpression* _tmp84_;
	ValaUnaryExpression* _tmp85_;
	ValaBlock* _tmp86_;
	ValaSourceReference* _tmp87_;
	ValaSourceReference* _tmp88_;
	ValaIfStatement* _tmp89_;
	ValaIfStatement* _tmp90_;
	ValaBlock* _tmp91_;
	ValaBlock* _tmp92_;
	ValaIfStatement* _tmp93_;
	ValaBlock* _tmp94_;
	ValaBlock* _tmp95_;
	ValaLocalVariable* _tmp96_;
	const gchar* _tmp97_;
	const gchar* _tmp98_;
	ValaSourceReference* _tmp99_;
	ValaSourceReference* _tmp100_;
	ValaMemberAccess* _tmp101_;
	ValaMemberAccess* _tmp102_;
	ValaSourceReference* _tmp103_;
	ValaSourceReference* _tmp104_;
	ValaBooleanLiteral* _tmp105_;
	ValaBooleanLiteral* _tmp106_;
	ValaSourceReference* _tmp107_;
	ValaSourceReference* _tmp108_;
	ValaAssignment* _tmp109_;
	ValaAssignment* _tmp110_;
	ValaSourceReference* _tmp111_;
	ValaSourceReference* _tmp112_;
	ValaExpressionStatement* _tmp113_;
	ValaExpressionStatement* _tmp114_;
	ValaBlock* _tmp115_;
	ValaBlock* _tmp116_;
	ValaBlock* _tmp117_;
	ValaSourceReference* _tmp118_;
	ValaSourceReference* _tmp119_;
	ValaLoop* _tmp120_;
	ValaLoop* _tmp121_;
	ValaBlock* parent_block = NULL;
	ValaCodeNode* _tmp122_;
	ValaCodeNode* _tmp123_;
	ValaBlock* _tmp124_;
	ValaBlock* _tmp125_;
	ValaBlock* _tmp126_;
	gboolean _tmp127_;
	gboolean _tmp128_;
	gboolean result = FALSE;
	self = (ValaDoStatement*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = vala_do_statement_get_condition (self);
	_tmp5_ = _tmp4_;
	if (vala_do_statement_always_true (self, _tmp5_)) {
		ValaLoop* loop = NULL;
		ValaBlock* _tmp6_;
		ValaBlock* _tmp7_;
		ValaSourceReference* _tmp8_;
		ValaSourceReference* _tmp9_;
		ValaLoop* _tmp10_;
		ValaBlock* parent_block = NULL;
		ValaCodeNode* _tmp11_;
		ValaCodeNode* _tmp12_;
		ValaBlock* _tmp13_;
		ValaLoop* _tmp14_;
		ValaLoop* _tmp15_;
		gboolean _tmp16_;
		gboolean _tmp17_;
		_tmp6_ = vala_do_statement_get_body (self);
		_tmp7_ = _tmp6_;
		_tmp8_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp9_ = _tmp8_;
		_tmp10_ = vala_loop_new (_tmp7_, _tmp9_);
		loop = _tmp10_;
		_tmp11_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
		_tmp12_ = _tmp11_;
		parent_block = G_TYPE_CHECK_INSTANCE_CAST (_tmp12_, VALA_TYPE_BLOCK, ValaBlock);
		_tmp13_ = parent_block;
		_tmp14_ = loop;
		vala_block_replace_statement (_tmp13_, (ValaStatement*) self, (ValaStatement*) _tmp14_);
		_tmp15_ = loop;
		if (!vala_code_node_check ((ValaCodeNode*) _tmp15_, context)) {
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		}
		_tmp16_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp17_ = _tmp16_;
		result = !_tmp17_;
		_vala_code_node_unref0 (loop);
		return result;
	}
	_tmp18_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp19_ = _tmp18_;
	_tmp20_ = vala_block_new (_tmp19_);
	block = _tmp20_;
	_tmp21_ = vala_code_context_get_analyzer (context);
	_tmp22_ = _tmp21_;
	_tmp23_ = _tmp22_->bool_type;
	_tmp24_ = vala_data_type_copy (_tmp23_);
	_tmp25_ = _tmp24_;
	_tmp26_ = vala_code_node_get_temp_name ();
	_tmp27_ = _tmp26_;
	_tmp28_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp29_ = _tmp28_;
	_tmp30_ = vala_boolean_literal_new (TRUE, _tmp29_);
	_tmp31_ = _tmp30_;
	_tmp32_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp33_ = _tmp32_;
	_tmp34_ = vala_local_variable_new (_tmp25_, _tmp27_, (ValaExpression*) _tmp31_, _tmp33_);
	_tmp35_ = _tmp34_;
	_vala_code_node_unref0 (_tmp31_);
	_g_free0 (_tmp27_);
	_vala_code_node_unref0 (_tmp25_);
	first_local = _tmp35_;
	_tmp36_ = block;
	_tmp37_ = first_local;
	_tmp38_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp39_ = _tmp38_;
	_tmp40_ = vala_declaration_statement_new ((ValaSymbol*) _tmp37_, _tmp39_);
	_tmp41_ = _tmp40_;
	vala_block_add_statement (_tmp36_, (ValaStatement*) _tmp41_);
	_vala_code_node_unref0 (_tmp41_);
	_tmp42_ = vala_do_statement_get_condition (self);
	_tmp43_ = _tmp42_;
	_tmp44_ = vala_do_statement_get_condition (self);
	_tmp45_ = _tmp44_;
	_tmp46_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp45_);
	_tmp47_ = _tmp46_;
	_tmp48_ = vala_unary_expression_new (VALA_UNARY_OPERATOR_LOGICAL_NEGATION, _tmp43_, _tmp47_);
	if_condition = _tmp48_;
	_tmp49_ = vala_do_statement_get_condition (self);
	_tmp50_ = _tmp49_;
	_tmp51_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp50_);
	_tmp52_ = _tmp51_;
	_tmp53_ = vala_block_new (_tmp52_);
	true_block = _tmp53_;
	_tmp54_ = true_block;
	_tmp55_ = vala_do_statement_get_condition (self);
	_tmp56_ = _tmp55_;
	_tmp57_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp56_);
	_tmp58_ = _tmp57_;
	_tmp59_ = vala_break_statement_new (_tmp58_);
	_tmp60_ = _tmp59_;
	vala_block_add_statement (_tmp54_, (ValaStatement*) _tmp60_);
	_vala_code_node_unref0 (_tmp60_);
	_tmp61_ = if_condition;
	_tmp62_ = true_block;
	_tmp63_ = vala_do_statement_get_condition (self);
	_tmp64_ = _tmp63_;
	_tmp65_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp64_);
	_tmp66_ = _tmp65_;
	_tmp67_ = vala_if_statement_new ((ValaExpression*) _tmp61_, _tmp62_, NULL, _tmp66_);
	if_stmt = _tmp67_;
	_tmp68_ = vala_do_statement_get_condition (self);
	_tmp69_ = _tmp68_;
	_tmp70_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp69_);
	_tmp71_ = _tmp70_;
	_tmp72_ = vala_block_new (_tmp71_);
	condition_block = _tmp72_;
	_tmp73_ = condition_block;
	_tmp74_ = if_stmt;
	vala_block_add_statement (_tmp73_, (ValaStatement*) _tmp74_);
	_tmp75_ = first_local;
	_tmp76_ = vala_symbol_get_name ((ValaSymbol*) _tmp75_);
	_tmp77_ = _tmp76_;
	_tmp78_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp79_ = _tmp78_;
	_tmp80_ = vala_member_access_new_simple (_tmp77_, _tmp79_);
	_tmp81_ = _tmp80_;
	_tmp82_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp83_ = _tmp82_;
	_tmp84_ = vala_unary_expression_new (VALA_UNARY_OPERATOR_LOGICAL_NEGATION, (ValaExpression*) _tmp81_, _tmp83_);
	_tmp85_ = _tmp84_;
	_tmp86_ = condition_block;
	_tmp87_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp88_ = _tmp87_;
	_tmp89_ = vala_if_statement_new ((ValaExpression*) _tmp85_, _tmp86_, NULL, _tmp88_);
	_tmp90_ = _tmp89_;
	_vala_code_node_unref0 (_tmp85_);
	_vala_code_node_unref0 (_tmp81_);
	first_if = _tmp90_;
	_tmp91_ = vala_do_statement_get_body (self);
	_tmp92_ = _tmp91_;
	_tmp93_ = first_if;
	vala_block_insert_statement (_tmp92_, 0, (ValaStatement*) _tmp93_);
	_tmp94_ = vala_do_statement_get_body (self);
	_tmp95_ = _tmp94_;
	_tmp96_ = first_local;
	_tmp97_ = vala_symbol_get_name ((ValaSymbol*) _tmp96_);
	_tmp98_ = _tmp97_;
	_tmp99_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp100_ = _tmp99_;
	_tmp101_ = vala_member_access_new_simple (_tmp98_, _tmp100_);
	_tmp102_ = _tmp101_;
	_tmp103_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp104_ = _tmp103_;
	_tmp105_ = vala_boolean_literal_new (FALSE, _tmp104_);
	_tmp106_ = _tmp105_;
	_tmp107_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp108_ = _tmp107_;
	_tmp109_ = vala_assignment_new ((ValaExpression*) _tmp102_, (ValaExpression*) _tmp106_, VALA_ASSIGNMENT_OPERATOR_SIMPLE, _tmp108_);
	_tmp110_ = _tmp109_;
	_tmp111_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp112_ = _tmp111_;
	_tmp113_ = vala_expression_statement_new ((ValaExpression*) _tmp110_, _tmp112_);
	_tmp114_ = _tmp113_;
	vala_block_insert_statement (_tmp95_, 1, (ValaStatement*) _tmp114_);
	_vala_code_node_unref0 (_tmp114_);
	_vala_code_node_unref0 (_tmp110_);
	_vala_code_node_unref0 (_tmp106_);
	_vala_code_node_unref0 (_tmp102_);
	_tmp115_ = block;
	_tmp116_ = vala_do_statement_get_body (self);
	_tmp117_ = _tmp116_;
	_tmp118_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp119_ = _tmp118_;
	_tmp120_ = vala_loop_new (_tmp117_, _tmp119_);
	_tmp121_ = _tmp120_;
	vala_block_add_statement (_tmp115_, (ValaStatement*) _tmp121_);
	_vala_code_node_unref0 (_tmp121_);
	_tmp122_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp123_ = _tmp122_;
	parent_block = G_TYPE_CHECK_INSTANCE_CAST (_tmp123_, VALA_TYPE_BLOCK, ValaBlock);
	_tmp124_ = parent_block;
	_tmp125_ = block;
	vala_block_replace_statement (_tmp124_, (ValaStatement*) self, (ValaStatement*) _tmp125_);
	_tmp126_ = block;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp126_, context)) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
	}
	_tmp127_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp128_ = _tmp127_;
	result = !_tmp128_;
	_vala_code_node_unref0 (first_if);
	_vala_code_node_unref0 (condition_block);
	_vala_code_node_unref0 (if_stmt);
	_vala_code_node_unref0 (true_block);
	_vala_code_node_unref0 (if_condition);
	_vala_code_node_unref0 (first_local);
	_vala_code_node_unref0 (block);
	return result;
}

static void
vala_do_statement_class_init (ValaDoStatementClass * klass,
                              gpointer klass_data)
{
	vala_do_statement_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_do_statement_finalize;
	g_type_class_adjust_private_offset (klass, &ValaDoStatement_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_do_statement_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_do_statement_real_accept_children;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_do_statement_real_replace_expression;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_do_statement_real_check;
}

static void
vala_do_statement_vala_statement_interface_init (ValaStatementIface * iface,
                                                 gpointer iface_data)
{
	vala_do_statement_vala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
vala_do_statement_instance_init (ValaDoStatement * self,
                                 gpointer klass)
{
	self->priv = vala_do_statement_get_instance_private (self);
}

static void
vala_do_statement_finalize (ValaCodeNode * obj)
{
	ValaDoStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_DO_STATEMENT, ValaDoStatement);
	_vala_code_node_unref0 (self->priv->_condition);
	_vala_code_node_unref0 (self->priv->_body);
	VALA_CODE_NODE_CLASS (vala_do_statement_parent_class)->finalize (obj);
}

/**
 * Represents a do iteration statement in the source code.
 */
static GType
vala_do_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaDoStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_do_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaDoStatement), 0, (GInstanceInitFunc) vala_do_statement_instance_init, NULL };
	static const GInterfaceInfo vala_statement_info = { (GInterfaceInitFunc) vala_do_statement_vala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType vala_do_statement_type_id;
	vala_do_statement_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaDoStatement", &g_define_type_info, 0);
	g_type_add_interface_static (vala_do_statement_type_id, VALA_TYPE_STATEMENT, &vala_statement_info);
	ValaDoStatement_private_offset = g_type_add_instance_private (vala_do_statement_type_id, sizeof (ValaDoStatementPrivate));
	return vala_do_statement_type_id;
}

GType
vala_do_statement_get_type (void)
{
	static volatile gsize vala_do_statement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_do_statement_type_id__volatile)) {
		GType vala_do_statement_type_id;
		vala_do_statement_type_id = vala_do_statement_get_type_once ();
		g_once_init_leave (&vala_do_statement_type_id__volatile, vala_do_statement_type_id);
	}
	return vala_do_statement_type_id__volatile;
}
