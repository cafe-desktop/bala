/* valaccodeexpression.c generated by valac, the Vala compiler
 * generated from valaccodeexpression.vala, do not modify */

/* valaccodeexpression.vala
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

#include "valaccode.h"
#include <glib.h>

static gpointer vala_ccode_expression_parent_class = NULL;

static void vala_ccode_expression_real_write_inner (ValaCCodeExpression* self,
                                             ValaCCodeWriter* writer);
static GType vala_ccode_expression_get_type_once (void);

static void
vala_ccode_expression_real_write_inner (ValaCCodeExpression* self,
                                        ValaCCodeWriter* writer)
{
	g_return_if_fail (writer != NULL);
	vala_ccode_node_write ((ValaCCodeNode*) self, writer);
}

void
vala_ccode_expression_write_inner (ValaCCodeExpression* self,
                                   ValaCCodeWriter* writer)
{
	g_return_if_fail (self != NULL);
	VALA_CCODE_EXPRESSION_GET_CLASS (self)->write_inner (self, writer);
}

ValaCCodeExpression*
vala_ccode_expression_construct (GType object_type)
{
	ValaCCodeExpression* self = NULL;
	self = (ValaCCodeExpression*) vala_ccode_node_construct (object_type);
	return self;
}

static void
vala_ccode_expression_class_init (ValaCCodeExpressionClass * klass,
                                  gpointer klass_data)
{
	vala_ccode_expression_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeExpressionClass *) klass)->write_inner = (void (*) (ValaCCodeExpression*, ValaCCodeWriter*)) vala_ccode_expression_real_write_inner;
}

static void
vala_ccode_expression_instance_init (ValaCCodeExpression * self,
                                     gpointer klass)
{
}

/**
 * Represents an expression node in the C code tree.
 */
static GType
vala_ccode_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeExpression), 0, (GInstanceInitFunc) vala_ccode_expression_instance_init, NULL };
	GType vala_ccode_expression_type_id;
	vala_ccode_expression_type_id = g_type_register_static (VALA_TYPE_CCODE_NODE, "ValaCCodeExpression", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return vala_ccode_expression_type_id;
}

GType
vala_ccode_expression_get_type (void)
{
	static volatile gsize vala_ccode_expression_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_expression_type_id__volatile)) {
		GType vala_ccode_expression_type_id;
		vala_ccode_expression_type_id = vala_ccode_expression_get_type_once ();
		g_once_init_leave (&vala_ccode_expression_type_id__volatile, vala_ccode_expression_type_id);
	}
	return vala_ccode_expression_type_id__volatile;
}

