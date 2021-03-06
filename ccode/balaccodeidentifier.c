/* balaccodeidentifier.c generated by balac, the Bala compiler
 * generated from balaccodeidentifier.bala, do not modify */

/* balaccodeidentifier.bala
 *
 * Copyright (C) 2006  Jürg Billeter
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
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#define _g_free0(var) (var = (g_free (var), NULL))

struct _BalaCCodeIdentifierPrivate {
	gchar* _name;
};

static gint BalaCCodeIdentifier_private_offset;
static gpointer bala_ccode_identifier_parent_class = NULL;

static void bala_ccode_identifier_real_write (BalaCCodeNode* base,
                                       BalaCCodeWriter* writer);
static void bala_ccode_identifier_finalize (BalaCCodeNode * obj);
static GType bala_ccode_identifier_get_type_once (void);

static inline gpointer
bala_ccode_identifier_get_instance_private (BalaCCodeIdentifier* self)
{
	return G_STRUCT_MEMBER_P (self, BalaCCodeIdentifier_private_offset);
}

const gchar*
bala_ccode_identifier_get_name (BalaCCodeIdentifier* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}

void
bala_ccode_identifier_set_name (BalaCCodeIdentifier* self,
                                const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp0_;
}

BalaCCodeIdentifier*
bala_ccode_identifier_construct (GType object_type,
                                 const gchar* _name)
{
	BalaCCodeIdentifier* self = NULL;
	g_return_val_if_fail (_name != NULL, NULL);
	self = (BalaCCodeIdentifier*) bala_ccode_expression_construct (object_type);
	bala_ccode_identifier_set_name (self, _name);
	return self;
}

BalaCCodeIdentifier*
bala_ccode_identifier_new (const gchar* _name)
{
	return bala_ccode_identifier_construct (BALA_TYPE_CCODE_IDENTIFIER, _name);
}

static void
bala_ccode_identifier_real_write (BalaCCodeNode* base,
                                  BalaCCodeWriter* writer)
{
	BalaCCodeIdentifier * self;
	const gchar* _tmp0_;
	self = (BalaCCodeIdentifier*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = self->priv->_name;
	bala_ccode_writer_write_string (writer, _tmp0_);
}

static void
bala_ccode_identifier_class_init (BalaCCodeIdentifierClass * klass,
                                  gpointer klass_data)
{
	bala_ccode_identifier_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeNodeClass *) klass)->finalize = bala_ccode_identifier_finalize;
	g_type_class_adjust_private_offset (klass, &BalaCCodeIdentifier_private_offset);
	((BalaCCodeNodeClass *) klass)->write = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_identifier_real_write;
}

static void
bala_ccode_identifier_instance_init (BalaCCodeIdentifier * self,
                                     gpointer klass)
{
	self->priv = bala_ccode_identifier_get_instance_private (self);
}

static void
bala_ccode_identifier_finalize (BalaCCodeNode * obj)
{
	BalaCCodeIdentifier * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_IDENTIFIER, BalaCCodeIdentifier);
	_g_free0 (self->priv->_name);
	BALA_CCODE_NODE_CLASS (bala_ccode_identifier_parent_class)->finalize (obj);
}

/**
 * Represents a identifier in the C code.
 */
static GType
bala_ccode_identifier_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeIdentifierClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_identifier_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeIdentifier), 0, (GInstanceInitFunc) bala_ccode_identifier_instance_init, NULL };
	GType bala_ccode_identifier_type_id;
	bala_ccode_identifier_type_id = g_type_register_static (BALA_TYPE_CCODE_EXPRESSION, "BalaCCodeIdentifier", &g_define_type_info, 0);
	BalaCCodeIdentifier_private_offset = g_type_add_instance_private (bala_ccode_identifier_type_id, sizeof (BalaCCodeIdentifierPrivate));
	return bala_ccode_identifier_type_id;
}

GType
bala_ccode_identifier_get_type (void)
{
	static volatile gsize bala_ccode_identifier_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_identifier_type_id__volatile)) {
		GType bala_ccode_identifier_type_id;
		bala_ccode_identifier_type_id = bala_ccode_identifier_get_type_once ();
		g_once_init_leave (&bala_ccode_identifier_type_id__volatile, bala_ccode_identifier_type_id);
	}
	return bala_ccode_identifier_type_id__volatile;
}

