/* baladynamicmethod.c generated by balac, the Bala compiler
 * generated from baladynamicmethod.bala, do not modify */

/* baladynamicmethod.bala
 *
 * Copyright (C) 2007-2008  Jürg Billeter
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
#include <glib.h>
#include <stdlib.h>
#include <string.h>

#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))

struct _BalaDynamicMethodPrivate {
	BalaDataType* _dynamic_type;
	BalaMethodCall* _invocation;
};

static gint BalaDynamicMethod_private_offset;
static gpointer bala_dynamic_method_parent_class = NULL;

static gboolean bala_dynamic_method_real_check (BalaCodeNode* base,
                                         BalaCodeContext* context);
static void bala_dynamic_method_finalize (BalaCodeNode * obj);
static GType bala_dynamic_method_get_type_once (void);

static inline gpointer
bala_dynamic_method_get_instance_private (BalaDynamicMethod* self)
{
	return G_STRUCT_MEMBER_P (self, BalaDynamicMethod_private_offset);
}

BalaDataType*
bala_dynamic_method_get_dynamic_type (BalaDynamicMethod* self)
{
	BalaDataType* result;
	BalaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_dynamic_type;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

void
bala_dynamic_method_set_dynamic_type (BalaDynamicMethod* self,
                                      BalaDataType* value)
{
	BalaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_dynamic_type);
	self->priv->_dynamic_type = _tmp0_;
}

BalaMethodCall*
bala_dynamic_method_get_invocation (BalaDynamicMethod* self)
{
	BalaMethodCall* result;
	BalaMethodCall* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_invocation;
	result = _tmp0_;
	return result;
}

void
bala_dynamic_method_set_invocation (BalaDynamicMethod* self,
                                    BalaMethodCall* value)
{
	BalaMethodCall* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_node_ref0 (value);
	_bala_code_node_unref0 (self->priv->_invocation);
	self->priv->_invocation = _tmp0_;
}

BalaDynamicMethod*
bala_dynamic_method_construct (GType object_type,
                               BalaDataType* dynamic_type,
                               const gchar* name,
                               BalaDataType* return_type,
                               BalaSourceReference* source_reference,
                               BalaComment* comment)
{
	BalaDynamicMethod* self = NULL;
	g_return_val_if_fail (dynamic_type != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (return_type != NULL, NULL);
	self = (BalaDynamicMethod*) bala_method_construct (object_type, name, return_type, source_reference, comment);
	bala_dynamic_method_set_dynamic_type (self, dynamic_type);
	return self;
}

BalaDynamicMethod*
bala_dynamic_method_new (BalaDataType* dynamic_type,
                         const gchar* name,
                         BalaDataType* return_type,
                         BalaSourceReference* source_reference,
                         BalaComment* comment)
{
	return bala_dynamic_method_construct (BALA_TYPE_DYNAMIC_METHOD, dynamic_type, name, return_type, source_reference, comment);
}

static gboolean
bala_dynamic_method_real_check (BalaCodeNode* base,
                                BalaCodeContext* context)
{
	BalaDynamicMethod * self;
	gboolean result = FALSE;
	self = (BalaDynamicMethod*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	result = TRUE;
	return result;
}

static void
bala_dynamic_method_class_init (BalaDynamicMethodClass * klass,
                                gpointer klass_data)
{
	bala_dynamic_method_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_dynamic_method_finalize;
	g_type_class_adjust_private_offset (klass, &BalaDynamicMethod_private_offset);
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_dynamic_method_real_check;
}

static void
bala_dynamic_method_instance_init (BalaDynamicMethod * self,
                                   gpointer klass)
{
	self->priv = bala_dynamic_method_get_instance_private (self);
}

static void
bala_dynamic_method_finalize (BalaCodeNode * obj)
{
	BalaDynamicMethod * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_DYNAMIC_METHOD, BalaDynamicMethod);
	_bala_code_node_unref0 (self->priv->_dynamic_type);
	_bala_code_node_unref0 (self->priv->_invocation);
	BALA_CODE_NODE_CLASS (bala_dynamic_method_parent_class)->finalize (obj);
}

/**
 * Represents a late bound method.
 */
static GType
bala_dynamic_method_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaDynamicMethodClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_dynamic_method_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaDynamicMethod), 0, (GInstanceInitFunc) bala_dynamic_method_instance_init, NULL };
	GType bala_dynamic_method_type_id;
	bala_dynamic_method_type_id = g_type_register_static (BALA_TYPE_METHOD, "BalaDynamicMethod", &g_define_type_info, 0);
	BalaDynamicMethod_private_offset = g_type_add_instance_private (bala_dynamic_method_type_id, sizeof (BalaDynamicMethodPrivate));
	return bala_dynamic_method_type_id;
}

GType
bala_dynamic_method_get_type (void)
{
	static volatile gsize bala_dynamic_method_type_id__volatile = 0;
	if (g_once_init_enter (&bala_dynamic_method_type_id__volatile)) {
		GType bala_dynamic_method_type_id;
		bala_dynamic_method_type_id = bala_dynamic_method_get_type_once ();
		g_once_init_leave (&bala_dynamic_method_type_id__volatile, bala_dynamic_method_type_id);
	}
	return bala_dynamic_method_type_id__volatile;
}

