/* balaccodestruct.c generated by balac, the Bala compiler
 * generated from balaccodestruct.bala, do not modify */

/* balaccodestruct.bala
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

#include "balaccode.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <balagee.h>
#include <glib-object.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _bala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_ccode_node_unref (var), NULL)))

struct _BalaCCodeStructPrivate {
	gchar* _name;
	BalaList* declarations;
};

static gint BalaCCodeStruct_private_offset;
static gpointer bala_ccode_struct_parent_class = NULL;

static void bala_ccode_struct_real_write (BalaCCodeNode* base,
                                   BalaCCodeWriter* writer);
static void bala_ccode_struct_finalize (BalaCCodeNode * obj);
static GType bala_ccode_struct_get_type_once (void);

static inline gpointer
bala_ccode_struct_get_instance_private (BalaCCodeStruct* self)
{
	return G_STRUCT_MEMBER_P (self, BalaCCodeStruct_private_offset);
}

const gchar*
bala_ccode_struct_get_name (BalaCCodeStruct* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}

void
bala_ccode_struct_set_name (BalaCCodeStruct* self,
                            const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp0_;
}

gboolean
bala_ccode_struct_get_is_empty (BalaCCodeStruct* self)
{
	gboolean result;
	BalaList* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->declarations;
	_tmp1_ = bala_collection_get_size ((BalaCollection*) _tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_ == 0;
	return result;
}

BalaCCodeStruct*
bala_ccode_struct_construct (GType object_type,
                             const gchar* name)
{
	BalaCCodeStruct* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (BalaCCodeStruct*) bala_ccode_node_construct (object_type);
	bala_ccode_struct_set_name (self, name);
	return self;
}

BalaCCodeStruct*
bala_ccode_struct_new (const gchar* name)
{
	return bala_ccode_struct_construct (BALA_TYPE_CCODE_STRUCT, name);
}

/**
 * Adds the specified declaration as member to this struct.
 *
 * @param decl a variable declaration
 */
void
bala_ccode_struct_add_declaration (BalaCCodeStruct* self,
                                   BalaCCodeDeclaration* decl)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (decl != NULL);
	_tmp0_ = self->priv->declarations;
	bala_collection_add ((BalaCollection*) _tmp0_, decl);
}

/**
 * Adds a variable with the specified type and name to this struct.
 *
 * @param type_name field type
 * @param name      member name
 */
void
bala_ccode_struct_add_field (BalaCCodeStruct* self,
                             const gchar* type_name,
                             const gchar* name,
                             BalaCCodeModifiers modifiers,
                             BalaCCodeDeclaratorSuffix* declarator_suffix)
{
	BalaCCodeDeclaration* decl = NULL;
	BalaCCodeDeclaration* _tmp0_;
	BalaCCodeVariableDeclarator* _tmp1_;
	BalaCCodeVariableDeclarator* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (type_name != NULL);
	g_return_if_fail (name != NULL);
	_tmp0_ = bala_ccode_declaration_new (type_name);
	decl = _tmp0_;
	_tmp1_ = bala_ccode_variable_declarator_new (name, NULL, declarator_suffix);
	_tmp2_ = _tmp1_;
	bala_ccode_declaration_add_declarator (decl, (BalaCCodeDeclarator*) _tmp2_);
	_bala_ccode_node_unref0 (_tmp2_);
	bala_ccode_node_set_modifiers ((BalaCCodeNode*) decl, modifiers);
	bala_ccode_struct_add_declaration (self, decl);
	_bala_ccode_node_unref0 (decl);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static void
bala_ccode_struct_real_write (BalaCCodeNode* base,
                              BalaCCodeWriter* writer)
{
	BalaCCodeStruct * self;
	const gchar* _tmp0_;
	BalaCCodeModifiers _tmp11_;
	BalaCCodeModifiers _tmp12_;
	self = (BalaCCodeStruct*) base;
	g_return_if_fail (writer != NULL);
	bala_ccode_writer_write_string (writer, "struct ");
	_tmp0_ = self->priv->_name;
	bala_ccode_writer_write_string (writer, _tmp0_);
	bala_ccode_writer_write_begin_block (writer);
	{
		BalaList* _decl_list = NULL;
		BalaList* _tmp1_;
		BalaList* _tmp2_;
		gint _decl_size = 0;
		BalaList* _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _decl_index = 0;
		_tmp1_ = self->priv->declarations;
		_tmp2_ = _bala_iterable_ref0 (_tmp1_);
		_decl_list = _tmp2_;
		_tmp3_ = _decl_list;
		_tmp4_ = bala_collection_get_size ((BalaCollection*) _tmp3_);
		_tmp5_ = _tmp4_;
		_decl_size = _tmp5_;
		_decl_index = -1;
		while (TRUE) {
			gint _tmp6_;
			gint _tmp7_;
			BalaCCodeDeclaration* decl = NULL;
			BalaList* _tmp8_;
			gpointer _tmp9_;
			BalaCCodeDeclaration* _tmp10_;
			_decl_index = _decl_index + 1;
			_tmp6_ = _decl_index;
			_tmp7_ = _decl_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _decl_list;
			_tmp9_ = bala_list_get (_tmp8_, _decl_index);
			decl = (BalaCCodeDeclaration*) _tmp9_;
			_tmp10_ = decl;
			bala_ccode_node_write_declaration ((BalaCCodeNode*) _tmp10_, writer);
			_bala_ccode_node_unref0 (decl);
		}
		_bala_iterable_unref0 (_decl_list);
	}
	bala_ccode_writer_write_end_block (writer);
	_tmp11_ = bala_ccode_node_get_modifiers ((BalaCCodeNode*) self);
	_tmp12_ = _tmp11_;
	if ((_tmp12_ & BALA_CCODE_MODIFIERS_DEPRECATED) == BALA_CCODE_MODIFIERS_DEPRECATED) {
		bala_ccode_writer_write_string (writer, " G_GNUC_DEPRECATED");
	}
	bala_ccode_writer_write_string (writer, ";");
	bala_ccode_writer_write_newline (writer);
	bala_ccode_writer_write_newline (writer);
}

static void
bala_ccode_struct_class_init (BalaCCodeStructClass * klass,
                              gpointer klass_data)
{
	bala_ccode_struct_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeNodeClass *) klass)->finalize = bala_ccode_struct_finalize;
	g_type_class_adjust_private_offset (klass, &BalaCCodeStruct_private_offset);
	((BalaCCodeNodeClass *) klass)->write = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_struct_real_write;
}

static void
bala_ccode_struct_instance_init (BalaCCodeStruct * self,
                                 gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	self->priv = bala_ccode_struct_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_CCODE_DECLARATION, (GBoxedCopyFunc) bala_ccode_node_ref, (GDestroyNotify) bala_ccode_node_unref, _tmp0_);
	self->priv->declarations = (BalaList*) _tmp1_;
}

static void
bala_ccode_struct_finalize (BalaCCodeNode * obj)
{
	BalaCCodeStruct * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_STRUCT, BalaCCodeStruct);
	_g_free0 (self->priv->_name);
	_bala_iterable_unref0 (self->priv->declarations);
	BALA_CCODE_NODE_CLASS (bala_ccode_struct_parent_class)->finalize (obj);
}

/**
 * Represents a struct declaration in the C code.
 */
static GType
bala_ccode_struct_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeStructClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_struct_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeStruct), 0, (GInstanceInitFunc) bala_ccode_struct_instance_init, NULL };
	GType bala_ccode_struct_type_id;
	bala_ccode_struct_type_id = g_type_register_static (BALA_TYPE_CCODE_NODE, "BalaCCodeStruct", &g_define_type_info, 0);
	BalaCCodeStruct_private_offset = g_type_add_instance_private (bala_ccode_struct_type_id, sizeof (BalaCCodeStructPrivate));
	return bala_ccode_struct_type_id;
}

GType
bala_ccode_struct_get_type (void)
{
	static volatile gsize bala_ccode_struct_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_struct_type_id__volatile)) {
		GType bala_ccode_struct_type_id;
		bala_ccode_struct_type_id = bala_ccode_struct_get_type_once ();
		g_once_init_leave (&bala_ccode_struct_type_id__volatile, bala_ccode_struct_type_id);
	}
	return bala_ccode_struct_type_id__volatile;
}

