/* balabreakstatement.c generated by balac, the Bala compiler
 * generated from balabreakstatement.bala, do not modify */

/* balabreakstatement.bala
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
#include <glib.h>

static gpointer bala_break_statement_parent_class = NULL;
static BalaStatementIface * bala_break_statement_bala_statement_parent_iface = NULL;

static void bala_break_statement_real_accept (BalaCodeNode* base,
                                       BalaCodeVisitor* visitor);
static void bala_break_statement_real_emit (BalaCodeNode* base,
                                     BalaCodeGenerator* codegen);
static GType bala_break_statement_get_type_once (void);

/**
 * Creates a new break statement.
 *
 * @param source reference to source code
 * @return       newly created break statement
 */
BalaBreakStatement*
bala_break_statement_construct (GType object_type,
                                BalaSourceReference* source)
{
	BalaBreakStatement* self = NULL;
	self = (BalaBreakStatement*) bala_code_node_construct (object_type);
	bala_code_node_set_source_reference ((BalaCodeNode*) self, source);
	return self;
}

BalaBreakStatement*
bala_break_statement_new (BalaSourceReference* source)
{
	return bala_break_statement_construct (BALA_TYPE_BREAK_STATEMENT, source);
}

static void
bala_break_statement_real_accept (BalaCodeNode* base,
                                  BalaCodeVisitor* visitor)
{
	BalaBreakStatement * self;
	self = (BalaBreakStatement*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_break_statement (visitor, self);
}

static void
bala_break_statement_real_emit (BalaCodeNode* base,
                                BalaCodeGenerator* codegen)
{
	BalaBreakStatement * self;
	self = (BalaBreakStatement*) base;
	g_return_if_fail (codegen != NULL);
	bala_code_visitor_visit_break_statement ((BalaCodeVisitor*) codegen, self);
}

static void
bala_break_statement_class_init (BalaBreakStatementClass * klass,
                                 gpointer klass_data)
{
	bala_break_statement_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_break_statement_real_accept;
	((BalaCodeNodeClass *) klass)->emit = (void (*) (BalaCodeNode*, BalaCodeGenerator*)) bala_break_statement_real_emit;
}

static void
bala_break_statement_bala_statement_interface_init (BalaStatementIface * iface,
                                                    gpointer iface_data)
{
	bala_break_statement_bala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
bala_break_statement_instance_init (BalaBreakStatement * self,
                                    gpointer klass)
{
}

/**
 * Represents a break statement in the source code.
 */
static GType
bala_break_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaBreakStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_break_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaBreakStatement), 0, (GInstanceInitFunc) bala_break_statement_instance_init, NULL };
	static const GInterfaceInfo bala_statement_info = { (GInterfaceInitFunc) bala_break_statement_bala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType bala_break_statement_type_id;
	bala_break_statement_type_id = g_type_register_static (BALA_TYPE_CODE_NODE, "BalaBreakStatement", &g_define_type_info, 0);
	g_type_add_interface_static (bala_break_statement_type_id, BALA_TYPE_STATEMENT, &bala_statement_info);
	return bala_break_statement_type_id;
}

GType
bala_break_statement_get_type (void)
{
	static volatile gsize bala_break_statement_type_id__volatile = 0;
	if (g_once_init_enter (&bala_break_statement_type_id__volatile)) {
		GType bala_break_statement_type_id;
		bala_break_statement_type_id = bala_break_statement_get_type_once ();
		g_once_init_leave (&bala_break_statement_type_id__volatile, bala_break_statement_type_id);
	}
	return bala_break_statement_type_id__volatile;
}

