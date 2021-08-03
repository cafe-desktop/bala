/* valatrystatement.c generated by valac, the Vala compiler
 * generated from valatrystatement.vala, do not modify */

/* valatrystatement.vala
 *
 * Copyright (C) 2007-2010  Jürg Billeter
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
#include <valagee.h>
#include <glib-object.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

struct _ValaTryStatementPrivate {
	gboolean _after_try_block_reachable;
	ValaBlock* _body;
	ValaBlock* _finally_body;
	ValaList* catch_clauses;
};

static gint ValaTryStatement_private_offset;
static gpointer vala_try_statement_parent_class = NULL;
static ValaStatementIface * vala_try_statement_vala_statement_parent_iface = NULL;

static void vala_try_statement_real_accept (ValaCodeNode* base,
                                     ValaCodeVisitor* visitor);
static void vala_try_statement_real_accept_children (ValaCodeNode* base,
                                              ValaCodeVisitor* visitor);
static void vala_try_statement_real_get_error_types (ValaCodeNode* base,
                                              ValaCollection* collection,
                                              ValaSourceReference* source_reference);
static gboolean vala_try_statement_real_check (ValaCodeNode* base,
                                        ValaCodeContext* context);
static void vala_try_statement_real_emit (ValaCodeNode* base,
                                   ValaCodeGenerator* codegen);
static void vala_try_statement_finalize (ValaCodeNode * obj);
static GType vala_try_statement_get_type_once (void);

static inline gpointer
vala_try_statement_get_instance_private (ValaTryStatement* self)
{
	return G_STRUCT_MEMBER_P (self, ValaTryStatement_private_offset);
}

ValaBlock*
vala_try_statement_get_body (ValaTryStatement* self)
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
vala_try_statement_set_body (ValaTryStatement* self,
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

ValaBlock*
vala_try_statement_get_finally_body (ValaTryStatement* self)
{
	ValaBlock* result;
	ValaBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_finally_body;
	result = _tmp0_;
	return result;
}

void
vala_try_statement_set_finally_body (ValaTryStatement* self,
                                     ValaBlock* value)
{
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_finally_body);
	self->priv->_finally_body = _tmp0_;
	_tmp1_ = self->priv->_finally_body;
	if (_tmp1_ != NULL) {
		ValaBlock* _tmp2_;
		_tmp2_ = self->priv->_finally_body;
		vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
	}
}

gboolean
vala_try_statement_get_after_try_block_reachable (ValaTryStatement* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_after_try_block_reachable;
	return result;
}

void
vala_try_statement_set_after_try_block_reachable (ValaTryStatement* self,
                                                  gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_after_try_block_reachable = value;
}

/**
 * Creates a new try statement.
 *
 * @param body             body of the try statement
 * @param finally_body     body of the optional finally clause
 * @param source_reference reference to source code
 * @return                 newly created try statement
 */
ValaTryStatement*
vala_try_statement_construct (GType object_type,
                              ValaBlock* body,
                              ValaBlock* finally_body,
                              ValaSourceReference* source_reference)
{
	ValaTryStatement* self = NULL;
	g_return_val_if_fail (body != NULL, NULL);
	self = (ValaTryStatement*) vala_code_node_construct (object_type);
	vala_try_statement_set_body (self, body);
	vala_try_statement_set_finally_body (self, finally_body);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaTryStatement*
vala_try_statement_new (ValaBlock* body,
                        ValaBlock* finally_body,
                        ValaSourceReference* source_reference)
{
	return vala_try_statement_construct (VALA_TYPE_TRY_STATEMENT, body, finally_body, source_reference);
}

/**
 * Appends the specified clause to the list of catch clauses.
 *
 * @param clause a catch clause
 */
void
vala_try_statement_add_catch_clause (ValaTryStatement* self,
                                     ValaCatchClause* clause)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (clause != NULL);
	vala_code_node_set_parent_node ((ValaCodeNode*) clause, (ValaCodeNode*) self);
	_tmp0_ = self->priv->catch_clauses;
	vala_collection_add ((ValaCollection*) _tmp0_, clause);
}

/**
 * Returns the list of catch clauses.
 *
 * @return list of catch clauses
 */
ValaList*
vala_try_statement_get_catch_clauses (ValaTryStatement* self)
{
	ValaList* _tmp0_;
	ValaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->catch_clauses;
	result = _tmp0_;
	return result;
}

static void
vala_try_statement_real_accept (ValaCodeNode* base,
                                ValaCodeVisitor* visitor)
{
	ValaTryStatement * self;
	self = (ValaTryStatement*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_try_statement (visitor, self);
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static void
vala_try_statement_real_accept_children (ValaCodeNode* base,
                                         ValaCodeVisitor* visitor)
{
	ValaTryStatement * self;
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	ValaBlock* _tmp12_;
	ValaBlock* _tmp13_;
	self = (ValaTryStatement*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_try_statement_get_body (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
	{
		ValaList* _clause_list = NULL;
		ValaList* _tmp2_;
		ValaList* _tmp3_;
		gint _clause_size = 0;
		ValaList* _tmp4_;
		gint _tmp5_;
		gint _tmp6_;
		gint _clause_index = 0;
		_tmp2_ = self->priv->catch_clauses;
		_tmp3_ = _vala_iterable_ref0 (_tmp2_);
		_clause_list = _tmp3_;
		_tmp4_ = _clause_list;
		_tmp5_ = vala_collection_get_size ((ValaCollection*) _tmp4_);
		_tmp6_ = _tmp5_;
		_clause_size = _tmp6_;
		_clause_index = -1;
		while (TRUE) {
			gint _tmp7_;
			gint _tmp8_;
			ValaCatchClause* clause = NULL;
			ValaList* _tmp9_;
			gpointer _tmp10_;
			ValaCatchClause* _tmp11_;
			_clause_index = _clause_index + 1;
			_tmp7_ = _clause_index;
			_tmp8_ = _clause_size;
			if (!(_tmp7_ < _tmp8_)) {
				break;
			}
			_tmp9_ = _clause_list;
			_tmp10_ = vala_list_get (_tmp9_, _clause_index);
			clause = (ValaCatchClause*) _tmp10_;
			_tmp11_ = clause;
			vala_code_node_accept ((ValaCodeNode*) _tmp11_, visitor);
			_vala_code_node_unref0 (clause);
		}
		_vala_iterable_unref0 (_clause_list);
	}
	_tmp12_ = vala_try_statement_get_finally_body (self);
	_tmp13_ = _tmp12_;
	if (_tmp13_ != NULL) {
		ValaBlock* _tmp14_;
		ValaBlock* _tmp15_;
		_tmp14_ = vala_try_statement_get_finally_body (self);
		_tmp15_ = _tmp14_;
		vala_code_node_accept ((ValaCodeNode*) _tmp15_, visitor);
	}
}

static void
vala_try_statement_real_get_error_types (ValaCodeNode* base,
                                         ValaCollection* collection,
                                         ValaSourceReference* source_reference)
{
	ValaTryStatement * self;
	ValaArrayList* error_types = NULL;
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	ValaBlock* _tmp2_;
	ValaBlock* _tmp3_;
	ValaArrayList* _tmp4_;
	ValaBlock* _tmp36_;
	ValaBlock* _tmp37_;
	self = (ValaTryStatement*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALA_TYPE_DATA_TYPE, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp0_);
	error_types = _tmp1_;
	_tmp2_ = vala_try_statement_get_body (self);
	_tmp3_ = _tmp2_;
	_tmp4_ = error_types;
	vala_code_node_get_error_types ((ValaCodeNode*) _tmp3_, (ValaCollection*) _tmp4_, source_reference);
	{
		ValaList* _clause_list = NULL;
		ValaList* _tmp5_;
		ValaList* _tmp6_;
		gint _clause_size = 0;
		ValaList* _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		gint _clause_index = 0;
		_tmp5_ = self->priv->catch_clauses;
		_tmp6_ = _vala_iterable_ref0 (_tmp5_);
		_clause_list = _tmp6_;
		_tmp7_ = _clause_list;
		_tmp8_ = vala_collection_get_size ((ValaCollection*) _tmp7_);
		_tmp9_ = _tmp8_;
		_clause_size = _tmp9_;
		_clause_index = -1;
		while (TRUE) {
			gint _tmp10_;
			gint _tmp11_;
			ValaCatchClause* clause = NULL;
			ValaList* _tmp12_;
			gpointer _tmp13_;
			ValaCatchClause* _tmp33_;
			ValaBlock* _tmp34_;
			ValaBlock* _tmp35_;
			_clause_index = _clause_index + 1;
			_tmp10_ = _clause_index;
			_tmp11_ = _clause_size;
			if (!(_tmp10_ < _tmp11_)) {
				break;
			}
			_tmp12_ = _clause_list;
			_tmp13_ = vala_list_get (_tmp12_, _clause_index);
			clause = (ValaCatchClause*) _tmp13_;
			{
				gint i = 0;
				i = 0;
				{
					gboolean _tmp14_ = FALSE;
					_tmp14_ = TRUE;
					while (TRUE) {
						ValaArrayList* _tmp16_;
						gint _tmp17_;
						gint _tmp18_;
						ValaDataType* error_type = NULL;
						ValaArrayList* _tmp19_;
						gpointer _tmp20_;
						gboolean _tmp21_ = FALSE;
						ValaCatchClause* _tmp22_;
						ValaDataType* _tmp23_;
						ValaDataType* _tmp24_;
						if (!_tmp14_) {
							gint _tmp15_;
							_tmp15_ = i;
							i = _tmp15_ + 1;
						}
						_tmp14_ = FALSE;
						_tmp16_ = error_types;
						_tmp17_ = vala_collection_get_size ((ValaCollection*) _tmp16_);
						_tmp18_ = _tmp17_;
						if (!(i < _tmp18_)) {
							break;
						}
						_tmp19_ = error_types;
						_tmp20_ = vala_list_get ((ValaList*) _tmp19_, i);
						error_type = (ValaDataType*) _tmp20_;
						_tmp22_ = clause;
						_tmp23_ = vala_catch_clause_get_error_type (_tmp22_);
						_tmp24_ = _tmp23_;
						if (_tmp24_ == NULL) {
							_tmp21_ = TRUE;
						} else {
							ValaDataType* _tmp25_;
							ValaCatchClause* _tmp26_;
							ValaDataType* _tmp27_;
							ValaDataType* _tmp28_;
							_tmp25_ = error_type;
							_tmp26_ = clause;
							_tmp27_ = vala_catch_clause_get_error_type (_tmp26_);
							_tmp28_ = _tmp27_;
							_tmp21_ = vala_data_type_compatible (_tmp25_, _tmp28_);
						}
						if (_tmp21_) {
							ValaArrayList* _tmp29_;
							gpointer _tmp30_;
							ValaDataType* _tmp31_;
							gint _tmp32_;
							_tmp29_ = error_types;
							_tmp30_ = vala_list_remove_at ((ValaList*) _tmp29_, i);
							_tmp31_ = (ValaDataType*) _tmp30_;
							_vala_code_node_unref0 (_tmp31_);
							_tmp32_ = i;
							i = _tmp32_ - 1;
						}
						_vala_code_node_unref0 (error_type);
					}
				}
			}
			_tmp33_ = clause;
			_tmp34_ = vala_catch_clause_get_body (_tmp33_);
			_tmp35_ = _tmp34_;
			vala_code_node_get_error_types ((ValaCodeNode*) _tmp35_, collection, source_reference);
			_vala_code_node_unref0 (clause);
		}
		_vala_iterable_unref0 (_clause_list);
	}
	_tmp36_ = vala_try_statement_get_finally_body (self);
	_tmp37_ = _tmp36_;
	if (_tmp37_ != NULL) {
		ValaBlock* _tmp38_;
		ValaBlock* _tmp39_;
		_tmp38_ = vala_try_statement_get_finally_body (self);
		_tmp39_ = _tmp38_;
		vala_code_node_get_error_types ((ValaCodeNode*) _tmp39_, collection, source_reference);
	}
	{
		ValaArrayList* _error_type_list = NULL;
		ValaArrayList* _tmp40_;
		ValaArrayList* _tmp41_;
		gint _error_type_size = 0;
		ValaArrayList* _tmp42_;
		gint _tmp43_;
		gint _tmp44_;
		gint _error_type_index = 0;
		_tmp40_ = error_types;
		_tmp41_ = _vala_iterable_ref0 (_tmp40_);
		_error_type_list = _tmp41_;
		_tmp42_ = _error_type_list;
		_tmp43_ = vala_collection_get_size ((ValaCollection*) _tmp42_);
		_tmp44_ = _tmp43_;
		_error_type_size = _tmp44_;
		_error_type_index = -1;
		while (TRUE) {
			gint _tmp45_;
			gint _tmp46_;
			ValaDataType* error_type = NULL;
			ValaArrayList* _tmp47_;
			gpointer _tmp48_;
			ValaDataType* _tmp49_;
			_error_type_index = _error_type_index + 1;
			_tmp45_ = _error_type_index;
			_tmp46_ = _error_type_size;
			if (!(_tmp45_ < _tmp46_)) {
				break;
			}
			_tmp47_ = _error_type_list;
			_tmp48_ = vala_list_get ((ValaList*) _tmp47_, _error_type_index);
			error_type = (ValaDataType*) _tmp48_;
			_tmp49_ = error_type;
			vala_collection_add (collection, _tmp49_);
			_vala_code_node_unref0 (error_type);
		}
		_vala_iterable_unref0 (_error_type_list);
	}
	_vala_iterable_unref0 (error_types);
}

static gboolean
vala_try_statement_real_check (ValaCodeNode* base,
                               ValaCodeContext* context)
{
	ValaTryStatement * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaProfile _tmp4_;
	ValaProfile _tmp5_;
	ValaBlock* _tmp8_;
	ValaBlock* _tmp9_;
	ValaBlock* _tmp20_;
	ValaBlock* _tmp21_;
	gboolean _tmp24_;
	gboolean _tmp25_;
	gboolean result = FALSE;
	self = (ValaTryStatement*) base;
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
	_tmp4_ = vala_code_context_get_profile (context);
	_tmp5_ = _tmp4_;
	if (_tmp5_ == VALA_PROFILE_POSIX) {
		ValaSourceReference* _tmp6_;
		ValaSourceReference* _tmp7_;
		_tmp6_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp7_ = _tmp6_;
		vala_report_error (_tmp7_, "`try' is not supported in POSIX profile");
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp8_ = vala_try_statement_get_body (self);
	_tmp9_ = _tmp8_;
	vala_code_node_check ((ValaCodeNode*) _tmp9_, context);
	{
		ValaList* _clause_list = NULL;
		ValaList* _tmp10_;
		ValaList* _tmp11_;
		gint _clause_size = 0;
		ValaList* _tmp12_;
		gint _tmp13_;
		gint _tmp14_;
		gint _clause_index = 0;
		_tmp10_ = self->priv->catch_clauses;
		_tmp11_ = _vala_iterable_ref0 (_tmp10_);
		_clause_list = _tmp11_;
		_tmp12_ = _clause_list;
		_tmp13_ = vala_collection_get_size ((ValaCollection*) _tmp12_);
		_tmp14_ = _tmp13_;
		_clause_size = _tmp14_;
		_clause_index = -1;
		while (TRUE) {
			gint _tmp15_;
			gint _tmp16_;
			ValaCatchClause* clause = NULL;
			ValaList* _tmp17_;
			gpointer _tmp18_;
			ValaCatchClause* _tmp19_;
			_clause_index = _clause_index + 1;
			_tmp15_ = _clause_index;
			_tmp16_ = _clause_size;
			if (!(_tmp15_ < _tmp16_)) {
				break;
			}
			_tmp17_ = _clause_list;
			_tmp18_ = vala_list_get (_tmp17_, _clause_index);
			clause = (ValaCatchClause*) _tmp18_;
			_tmp19_ = clause;
			vala_code_node_check ((ValaCodeNode*) _tmp19_, context);
			_vala_code_node_unref0 (clause);
		}
		_vala_iterable_unref0 (_clause_list);
	}
	_tmp20_ = vala_try_statement_get_finally_body (self);
	_tmp21_ = _tmp20_;
	if (_tmp21_ != NULL) {
		ValaBlock* _tmp22_;
		ValaBlock* _tmp23_;
		_tmp22_ = vala_try_statement_get_finally_body (self);
		_tmp23_ = _tmp22_;
		vala_code_node_check ((ValaCodeNode*) _tmp23_, context);
	}
	_tmp24_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp25_ = _tmp24_;
	result = !_tmp25_;
	return result;
}

static void
vala_try_statement_real_emit (ValaCodeNode* base,
                              ValaCodeGenerator* codegen)
{
	ValaTryStatement * self;
	self = (ValaTryStatement*) base;
	g_return_if_fail (codegen != NULL);
	vala_code_visitor_visit_try_statement ((ValaCodeVisitor*) codegen, self);
}

static void
vala_try_statement_class_init (ValaTryStatementClass * klass,
                               gpointer klass_data)
{
	vala_try_statement_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_try_statement_finalize;
	g_type_class_adjust_private_offset (klass, &ValaTryStatement_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_try_statement_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_try_statement_real_accept_children;
	((ValaCodeNodeClass *) klass)->get_error_types = (void (*) (ValaCodeNode*, ValaCollection*, ValaSourceReference*)) vala_try_statement_real_get_error_types;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_try_statement_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_try_statement_real_emit;
}

static void
vala_try_statement_vala_statement_interface_init (ValaStatementIface * iface,
                                                  gpointer iface_data)
{
	vala_try_statement_vala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
vala_try_statement_instance_init (ValaTryStatement * self,
                                  gpointer klass)
{
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	self->priv = vala_try_statement_get_instance_private (self);
	self->priv->_after_try_block_reachable = TRUE;
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALA_TYPE_CATCH_CLAUSE, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp0_);
	self->priv->catch_clauses = (ValaList*) _tmp1_;
}

static void
vala_try_statement_finalize (ValaCodeNode * obj)
{
	ValaTryStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_TRY_STATEMENT, ValaTryStatement);
	_vala_code_node_unref0 (self->priv->_body);
	_vala_code_node_unref0 (self->priv->_finally_body);
	_vala_iterable_unref0 (self->priv->catch_clauses);
	VALA_CODE_NODE_CLASS (vala_try_statement_parent_class)->finalize (obj);
}

/**
 * Represents a try statement in the source code.
 */
static GType
vala_try_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaTryStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_try_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaTryStatement), 0, (GInstanceInitFunc) vala_try_statement_instance_init, NULL };
	static const GInterfaceInfo vala_statement_info = { (GInterfaceInitFunc) vala_try_statement_vala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType vala_try_statement_type_id;
	vala_try_statement_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaTryStatement", &g_define_type_info, 0);
	g_type_add_interface_static (vala_try_statement_type_id, VALA_TYPE_STATEMENT, &vala_statement_info);
	ValaTryStatement_private_offset = g_type_add_instance_private (vala_try_statement_type_id, sizeof (ValaTryStatementPrivate));
	return vala_try_statement_type_id;
}

GType
vala_try_statement_get_type (void)
{
	static volatile gsize vala_try_statement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_try_statement_type_id__volatile)) {
		GType vala_try_statement_type_id;
		vala_try_statement_type_id = vala_try_statement_get_type_once ();
		g_once_init_leave (&vala_try_statement_type_id__volatile, vala_try_statement_type_id);
	}
	return vala_try_statement_type_id__volatile;
}

