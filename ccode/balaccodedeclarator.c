/* balaccodedeclarator.c generated by balac, the Bala compiler
 * generated from balaccodedeclarator.bala, do not modify */

/* balaccodedeclarator.bala
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

#include "balaccode.h"
#include <glib.h>

static gpointer bala_ccode_declarator_parent_class = NULL;

static void bala_ccode_declarator_real_write_initialization (BalaCCodeDeclarator* self,
                                                      BalaCCodeWriter* writer);
static GType bala_ccode_declarator_get_type_once (void);

/**
 * Writes initialization statements for this declarator with the
 * specified C code writer if necessary.
 *
 * @param writer a C code writer
 */
static void
bala_ccode_declarator_real_write_initialization (BalaCCodeDeclarator* self,
                                                 BalaCCodeWriter* writer)
{
	g_return_if_fail (writer != NULL);
}

void
bala_ccode_declarator_write_initialization (BalaCCodeDeclarator* self,
                                            BalaCCodeWriter* writer)
{
	g_return_if_fail (self != NULL);
	BALA_CCODE_DECLARATOR_GET_CLASS (self)->write_initialization (self, writer);
}

BalaCCodeDeclarator*
bala_ccode_declarator_construct (GType object_type)
{
	BalaCCodeDeclarator* self = NULL;
	self = (BalaCCodeDeclarator*) bala_ccode_node_construct (object_type);
	return self;
}

static void
bala_ccode_declarator_class_init (BalaCCodeDeclaratorClass * klass,
                                  gpointer klass_data)
{
	bala_ccode_declarator_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeDeclaratorClass *) klass)->write_initialization = (void (*) (BalaCCodeDeclarator*, BalaCCodeWriter*)) bala_ccode_declarator_real_write_initialization;
}

static void
bala_ccode_declarator_instance_init (BalaCCodeDeclarator * self,
                                     gpointer klass)
{
}

/**
 * Represents a variable or function pointer declarator in the C code.
 */
static GType
bala_ccode_declarator_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeDeclaratorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_declarator_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeDeclarator), 0, (GInstanceInitFunc) bala_ccode_declarator_instance_init, NULL };
	GType bala_ccode_declarator_type_id;
	bala_ccode_declarator_type_id = g_type_register_static (BALA_TYPE_CCODE_NODE, "BalaCCodeDeclarator", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return bala_ccode_declarator_type_id;
}

GType
bala_ccode_declarator_get_type (void)
{
	static volatile gsize bala_ccode_declarator_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_declarator_type_id__volatile)) {
		GType bala_ccode_declarator_type_id;
		bala_ccode_declarator_type_id = bala_ccode_declarator_get_type_once ();
		g_once_init_leave (&bala_ccode_declarator_type_id__volatile, bala_ccode_declarator_type_id);
	}
	return bala_ccode_declarator_type_id__volatile;
}

