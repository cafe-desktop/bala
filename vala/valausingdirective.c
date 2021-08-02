/* valausingdirective.c generated by valac, the Vala compiler
 * generated from valausingdirective.vala, do not modify */

/* valausingdirective.vala
 *
 * Copyright (C) 2006-2008  Jürg Billeter
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

struct _ValaUsingDirectivePrivate {
	ValaSymbol* _namespace_symbol;
	ValaUnresolvedSymbol* unresolved_symbol;
};

static gint ValaUsingDirective_private_offset;
static gpointer vala_using_directive_parent_class = NULL;

static void vala_using_directive_real_accept (ValaCodeNode* base,
                                       ValaCodeVisitor* visitor);
static void vala_using_directive_finalize (ValaCodeNode * obj);
static GType vala_using_directive_get_type_once (void);

static inline gpointer
vala_using_directive_get_instance_private (ValaUsingDirective* self)
{
	return G_STRUCT_MEMBER_P (self, ValaUsingDirective_private_offset);
}

ValaSymbol*
vala_using_directive_get_namespace_symbol (ValaUsingDirective* self)
{
	ValaSymbol* result;
	ValaUnresolvedSymbol* _tmp0_;
	ValaSymbol* _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->unresolved_symbol;
	if (_tmp0_ != NULL) {
		ValaUnresolvedSymbol* _tmp1_;
		_tmp1_ = self->priv->unresolved_symbol;
		result = (ValaSymbol*) _tmp1_;
		return result;
	}
	_tmp2_ = self->priv->_namespace_symbol;
	result = _tmp2_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_using_directive_set_namespace_symbol (ValaUsingDirective* self,
                                           ValaSymbol* value)
{
	g_return_if_fail (self != NULL);
	if (VALA_IS_UNRESOLVED_SYMBOL (value)) {
		ValaUnresolvedSymbol* _tmp0_;
		_tmp0_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (value, VALA_TYPE_UNRESOLVED_SYMBOL, ValaUnresolvedSymbol));
		_vala_code_node_unref0 (self->priv->unresolved_symbol);
		self->priv->unresolved_symbol = _tmp0_;
		self->priv->_namespace_symbol = NULL;
	} else {
		self->priv->_namespace_symbol = value;
		_vala_code_node_unref0 (self->priv->unresolved_symbol);
		self->priv->unresolved_symbol = NULL;
	}
}

/**
 * Creates a new using directive.
 *
 * @param namespace_symbol namespace symbol
 * @return                 newly created using directive
 */
ValaUsingDirective*
vala_using_directive_construct (GType object_type,
                                ValaSymbol* namespace_symbol,
                                ValaSourceReference* source_reference)
{
	ValaUsingDirective* self = NULL;
	g_return_val_if_fail (namespace_symbol != NULL, NULL);
	self = (ValaUsingDirective*) vala_code_node_construct (object_type);
	vala_using_directive_set_namespace_symbol (self, namespace_symbol);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaUsingDirective*
vala_using_directive_new (ValaSymbol* namespace_symbol,
                          ValaSourceReference* source_reference)
{
	return vala_using_directive_construct (VALA_TYPE_USING_DIRECTIVE, namespace_symbol, source_reference);
}

static void
vala_using_directive_real_accept (ValaCodeNode* base,
                                  ValaCodeVisitor* visitor)
{
	ValaUsingDirective * self;
	self = (ValaUsingDirective*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_using_directive (visitor, self);
}

static void
vala_using_directive_class_init (ValaUsingDirectiveClass * klass,
                                 gpointer klass_data)
{
	vala_using_directive_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_using_directive_finalize;
	g_type_class_adjust_private_offset (klass, &ValaUsingDirective_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_using_directive_real_accept;
}

static void
vala_using_directive_instance_init (ValaUsingDirective * self,
                                    gpointer klass)
{
	self->priv = vala_using_directive_get_instance_private (self);
}

static void
vala_using_directive_finalize (ValaCodeNode * obj)
{
	ValaUsingDirective * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_USING_DIRECTIVE, ValaUsingDirective);
	_vala_code_node_unref0 (self->priv->unresolved_symbol);
	VALA_CODE_NODE_CLASS (vala_using_directive_parent_class)->finalize (obj);
}

/**
 * A reference to a namespace symbol.
 */
static GType
vala_using_directive_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaUsingDirectiveClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_using_directive_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaUsingDirective), 0, (GInstanceInitFunc) vala_using_directive_instance_init, NULL };
	GType vala_using_directive_type_id;
	vala_using_directive_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaUsingDirective", &g_define_type_info, 0);
	ValaUsingDirective_private_offset = g_type_add_instance_private (vala_using_directive_type_id, sizeof (ValaUsingDirectivePrivate));
	return vala_using_directive_type_id;
}

GType
vala_using_directive_get_type (void)
{
	static volatile gsize vala_using_directive_type_id__volatile = 0;
	if (g_once_init_enter (&vala_using_directive_type_id__volatile)) {
		GType vala_using_directive_type_id;
		vala_using_directive_type_id = vala_using_directive_get_type_once ();
		g_once_init_leave (&vala_using_directive_type_id__volatile, vala_using_directive_type_id);
	}
	return vala_using_directive_type_id__volatile;
}

