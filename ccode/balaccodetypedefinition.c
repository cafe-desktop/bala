/* valaccodetypedefinition.c generated by valac, the Vala compiler
 * generated from valaccodetypedefinition.vala, do not modify */

/* valaccodetypedefinition.vala
 *
 * Copyright (C) 2006-2007  Jürg Billeter
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

#include "valaccode.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))

struct _ValaCCodeTypeDefinitionPrivate {
	gchar* _type_name;
	ValaCCodeDeclarator* _declarator;
};

static gint ValaCCodeTypeDefinition_private_offset;
static gpointer vala_ccode_type_definition_parent_class = NULL;

static void vala_ccode_type_definition_real_write (ValaCCodeNode* base,
                                            ValaCCodeWriter* writer);
static void vala_ccode_type_definition_real_write_declaration (ValaCCodeNode* base,
                                                        ValaCCodeWriter* writer);
static void vala_ccode_type_definition_finalize (ValaCCodeNode * obj);
static GType vala_ccode_type_definition_get_type_once (void);

static inline gpointer
vala_ccode_type_definition_get_instance_private (ValaCCodeTypeDefinition* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeTypeDefinition_private_offset);
}

const gchar*
vala_ccode_type_definition_get_type_name (ValaCCodeTypeDefinition* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_type_name;
	result = _tmp0_;
	return result;
}

void
vala_ccode_type_definition_set_type_name (ValaCCodeTypeDefinition* self,
                                          const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_type_name);
	self->priv->_type_name = _tmp0_;
}

ValaCCodeDeclarator*
vala_ccode_type_definition_get_declarator (ValaCCodeTypeDefinition* self)
{
	ValaCCodeDeclarator* result;
	ValaCCodeDeclarator* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_declarator;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_ccode_node_ref0 (gpointer self)
{
	return self ? vala_ccode_node_ref (self) : NULL;
}

void
vala_ccode_type_definition_set_declarator (ValaCCodeTypeDefinition* self,
                                           ValaCCodeDeclarator* value)
{
	ValaCCodeDeclarator* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_ccode_node_ref0 (value);
	_vala_ccode_node_unref0 (self->priv->_declarator);
	self->priv->_declarator = _tmp0_;
}

ValaCCodeTypeDefinition*
vala_ccode_type_definition_construct (GType object_type,
                                      const gchar* type,
                                      ValaCCodeDeclarator* decl)
{
	ValaCCodeTypeDefinition* self = NULL;
	g_return_val_if_fail (type != NULL, NULL);
	g_return_val_if_fail (decl != NULL, NULL);
	self = (ValaCCodeTypeDefinition*) vala_ccode_node_construct (object_type);
	vala_ccode_type_definition_set_type_name (self, type);
	vala_ccode_type_definition_set_declarator (self, decl);
	return self;
}

ValaCCodeTypeDefinition*
vala_ccode_type_definition_new (const gchar* type,
                                ValaCCodeDeclarator* decl)
{
	return vala_ccode_type_definition_construct (BALA_TYPE_CCODE_TYPE_DEFINITION, type, decl);
}

static void
vala_ccode_type_definition_real_write (ValaCCodeNode* base,
                                       ValaCCodeWriter* writer)
{
	ValaCCodeTypeDefinition * self;
	self = (ValaCCodeTypeDefinition*) base;
	g_return_if_fail (writer != NULL);
}

static void
vala_ccode_type_definition_real_write_declaration (ValaCCodeNode* base,
                                                   ValaCCodeWriter* writer)
{
	ValaCCodeTypeDefinition * self;
	const gchar* _tmp0_;
	ValaCCodeDeclarator* _tmp1_;
	ValaCCodeModifiers _tmp2_;
	ValaCCodeModifiers _tmp3_;
	self = (ValaCCodeTypeDefinition*) base;
	g_return_if_fail (writer != NULL);
	vala_ccode_writer_write_indent (writer, NULL);
	vala_ccode_writer_write_string (writer, "typedef ");
	_tmp0_ = self->priv->_type_name;
	vala_ccode_writer_write_string (writer, _tmp0_);
	vala_ccode_writer_write_string (writer, " ");
	_tmp1_ = self->priv->_declarator;
	vala_ccode_node_write_declaration ((ValaCCodeNode*) _tmp1_, writer);
	_tmp2_ = vala_ccode_node_get_modifiers ((ValaCCodeNode*) self);
	_tmp3_ = _tmp2_;
	if ((_tmp3_ & BALA_CCODE_MODIFIERS_DEPRECATED) == BALA_CCODE_MODIFIERS_DEPRECATED) {
		vala_ccode_writer_write_string (writer, " G_GNUC_DEPRECATED");
	}
	vala_ccode_writer_write_string (writer, ";");
	vala_ccode_writer_write_newline (writer);
}

static void
vala_ccode_type_definition_class_init (ValaCCodeTypeDefinitionClass * klass,
                                       gpointer klass_data)
{
	vala_ccode_type_definition_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_type_definition_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeTypeDefinition_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_type_definition_real_write;
	((ValaCCodeNodeClass *) klass)->write_declaration = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_type_definition_real_write_declaration;
}

static void
vala_ccode_type_definition_instance_init (ValaCCodeTypeDefinition * self,
                                          gpointer klass)
{
	self->priv = vala_ccode_type_definition_get_instance_private (self);
}

static void
vala_ccode_type_definition_finalize (ValaCCodeNode * obj)
{
	ValaCCodeTypeDefinition * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_TYPE_DEFINITION, ValaCCodeTypeDefinition);
	_g_free0 (self->priv->_type_name);
	_vala_ccode_node_unref0 (self->priv->_declarator);
	BALA_CCODE_NODE_CLASS (vala_ccode_type_definition_parent_class)->finalize (obj);
}

/**
 * Represents a typedef in the C code.
 */
static GType
vala_ccode_type_definition_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeTypeDefinitionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_type_definition_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeTypeDefinition), 0, (GInstanceInitFunc) vala_ccode_type_definition_instance_init, NULL };
	GType vala_ccode_type_definition_type_id;
	vala_ccode_type_definition_type_id = g_type_register_static (BALA_TYPE_CCODE_NODE, "ValaCCodeTypeDefinition", &g_define_type_info, 0);
	ValaCCodeTypeDefinition_private_offset = g_type_add_instance_private (vala_ccode_type_definition_type_id, sizeof (ValaCCodeTypeDefinitionPrivate));
	return vala_ccode_type_definition_type_id;
}

GType
vala_ccode_type_definition_get_type (void)
{
	static volatile gsize vala_ccode_type_definition_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_type_definition_type_id__volatile)) {
		GType vala_ccode_type_definition_type_id;
		vala_ccode_type_definition_type_id = vala_ccode_type_definition_get_type_once ();
		g_once_init_leave (&vala_ccode_type_definition_type_id__volatile, vala_ccode_type_definition_type_id);
	}
	return vala_ccode_type_definition_type_id__volatile;
}

