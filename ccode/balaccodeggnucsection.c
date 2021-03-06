/* balaccodeggnucsection.c generated by balac, the Bala compiler
 * generated from balaccodeggnucsection.bala, do not modify */

/* balaccodeggnucsection.bala
 *
 * Copyright (C) 2016  Rico Tzschichholz
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
 * 	Rico Tzschichholz <ricotz@ubuntu.com>
 */

#include "balaccode.h"
#include <glib.h>
#include <balagee.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

#define _bala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_ccode_node_unref (var), NULL)))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))

struct _BalaCCodeGGnucSectionPrivate {
	BalaGGnucSectionType _section_type;
};

static gint BalaCCodeGGnucSection_private_offset;
static gpointer bala_ccode_ggnuc_section_parent_class = NULL;

static void bala_ccode_ggnuc_section_real_write (BalaCCodeNode* base,
                                          BalaCCodeWriter* writer);
static void bala_ccode_ggnuc_section_real_write_declaration (BalaCCodeNode* base,
                                                      BalaCCodeWriter* writer);
static void bala_ccode_ggnuc_section_finalize (BalaCCodeNode * obj);
static GType bala_ccode_ggnuc_section_get_type_once (void);

static inline gpointer
bala_ccode_ggnuc_section_get_instance_private (BalaCCodeGGnucSection* self)
{
	return G_STRUCT_MEMBER_P (self, BalaCCodeGGnucSection_private_offset);
}

BalaGGnucSectionType
bala_ccode_ggnuc_section_get_section_type (BalaCCodeGGnucSection* self)
{
	BalaGGnucSectionType result;
	BalaGGnucSectionType _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_section_type;
	result = _tmp0_;
	return result;
}

void
bala_ccode_ggnuc_section_set_section_type (BalaCCodeGGnucSection* self,
                                           BalaGGnucSectionType value)
{
	g_return_if_fail (self != NULL);
	self->priv->_section_type = value;
}

BalaCCodeGGnucSection*
bala_ccode_ggnuc_section_construct (GType object_type,
                                    BalaGGnucSectionType t)
{
	BalaCCodeGGnucSection* self = NULL;
	self = (BalaCCodeGGnucSection*) bala_ccode_fragment_construct (object_type);
	bala_ccode_ggnuc_section_set_section_type (self, t);
	return self;
}

BalaCCodeGGnucSection*
bala_ccode_ggnuc_section_new (BalaGGnucSectionType t)
{
	return bala_ccode_ggnuc_section_construct (BALA_TYPE_CCODE_GGNUC_SECTION, t);
}

static void
bala_ccode_ggnuc_section_real_write (BalaCCodeNode* base,
                                     BalaCCodeWriter* writer)
{
	BalaCCodeGGnucSection * self;
	BalaGGnucSectionType _tmp0_;
	const gchar* _tmp1_;
	BalaGGnucSectionType _tmp11_;
	const gchar* _tmp12_;
	self = (BalaCCodeGGnucSection*) base;
	g_return_if_fail (writer != NULL);
	bala_ccode_writer_write_string (writer, "G_GNUC_BEGIN_");
	_tmp0_ = self->priv->_section_type;
	_tmp1_ = bala_ggnuc_section_type_to_string (_tmp0_);
	bala_ccode_writer_write_string (writer, _tmp1_);
	bala_ccode_writer_write_newline (writer);
	{
		BalaList* _node_list = NULL;
		BalaList* _tmp2_;
		gint _node_size = 0;
		BalaList* _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _node_index = 0;
		_tmp2_ = bala_ccode_fragment_get_children ((BalaCCodeFragment*) self);
		_node_list = _tmp2_;
		_tmp3_ = _node_list;
		_tmp4_ = bala_collection_get_size ((BalaCollection*) _tmp3_);
		_tmp5_ = _tmp4_;
		_node_size = _tmp5_;
		_node_index = -1;
		while (TRUE) {
			gint _tmp6_;
			gint _tmp7_;
			BalaCCodeNode* node = NULL;
			BalaList* _tmp8_;
			gpointer _tmp9_;
			BalaCCodeNode* _tmp10_;
			_node_index = _node_index + 1;
			_tmp6_ = _node_index;
			_tmp7_ = _node_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _node_list;
			_tmp9_ = bala_list_get (_tmp8_, _node_index);
			node = (BalaCCodeNode*) _tmp9_;
			_tmp10_ = node;
			bala_ccode_node_write_combined (_tmp10_, writer);
			_bala_ccode_node_unref0 (node);
		}
		_bala_iterable_unref0 (_node_list);
	}
	bala_ccode_writer_write_string (writer, "G_GNUC_END_");
	_tmp11_ = self->priv->_section_type;
	_tmp12_ = bala_ggnuc_section_type_to_string (_tmp11_);
	bala_ccode_writer_write_string (writer, _tmp12_);
	bala_ccode_writer_write_newline (writer);
}

static void
bala_ccode_ggnuc_section_real_write_declaration (BalaCCodeNode* base,
                                                 BalaCCodeWriter* writer)
{
	BalaCCodeGGnucSection * self;
	self = (BalaCCodeGGnucSection*) base;
	g_return_if_fail (writer != NULL);
}

static void
bala_ccode_ggnuc_section_class_init (BalaCCodeGGnucSectionClass * klass,
                                     gpointer klass_data)
{
	bala_ccode_ggnuc_section_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeNodeClass *) klass)->finalize = bala_ccode_ggnuc_section_finalize;
	g_type_class_adjust_private_offset (klass, &BalaCCodeGGnucSection_private_offset);
	((BalaCCodeNodeClass *) klass)->write = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_ggnuc_section_real_write;
	((BalaCCodeNodeClass *) klass)->write_declaration = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_ggnuc_section_real_write_declaration;
}

static void
bala_ccode_ggnuc_section_instance_init (BalaCCodeGGnucSection * self,
                                        gpointer klass)
{
	self->priv = bala_ccode_ggnuc_section_get_instance_private (self);
}

static void
bala_ccode_ggnuc_section_finalize (BalaCCodeNode * obj)
{
	BalaCCodeGGnucSection * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_GGNUC_SECTION, BalaCCodeGGnucSection);
	BALA_CCODE_NODE_CLASS (bala_ccode_ggnuc_section_parent_class)->finalize (obj);
}

/**
 * Represents a section that should be processed on condition.
 */
static GType
bala_ccode_ggnuc_section_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeGGnucSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_ggnuc_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeGGnucSection), 0, (GInstanceInitFunc) bala_ccode_ggnuc_section_instance_init, NULL };
	GType bala_ccode_ggnuc_section_type_id;
	bala_ccode_ggnuc_section_type_id = g_type_register_static (BALA_TYPE_CCODE_FRAGMENT, "BalaCCodeGGnucSection", &g_define_type_info, 0);
	BalaCCodeGGnucSection_private_offset = g_type_add_instance_private (bala_ccode_ggnuc_section_type_id, sizeof (BalaCCodeGGnucSectionPrivate));
	return bala_ccode_ggnuc_section_type_id;
}

GType
bala_ccode_ggnuc_section_get_type (void)
{
	static volatile gsize bala_ccode_ggnuc_section_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_ggnuc_section_type_id__volatile)) {
		GType bala_ccode_ggnuc_section_type_id;
		bala_ccode_ggnuc_section_type_id = bala_ccode_ggnuc_section_get_type_once ();
		g_once_init_leave (&bala_ccode_ggnuc_section_type_id__volatile, bala_ccode_ggnuc_section_type_id);
	}
	return bala_ccode_ggnuc_section_type_id__volatile;
}

const gchar*
bala_ggnuc_section_type_to_string (BalaGGnucSectionType self)
{
	const gchar* result = NULL;
	switch (self) {
		case BALA_GGNUC_SECTION_TYPE_IGNORE_DEPRECATIONS:
		{
			result = "IGNORE_DEPRECATIONS";
			return result;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
}

static GType
bala_ggnuc_section_type_get_type_once (void)
{
	static const GEnumValue values[] = {{BALA_GGNUC_SECTION_TYPE_IGNORE_DEPRECATIONS, "BALA_GGNUC_SECTION_TYPE_IGNORE_DEPRECATIONS", "ignore-deprecations"}, {0, NULL, NULL}};
	GType bala_ggnuc_section_type_type_id;
	bala_ggnuc_section_type_type_id = g_enum_register_static ("BalaGGnucSectionType", values);
	return bala_ggnuc_section_type_type_id;
}

GType
bala_ggnuc_section_type_get_type (void)
{
	static volatile gsize bala_ggnuc_section_type_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ggnuc_section_type_type_id__volatile)) {
		GType bala_ggnuc_section_type_type_id;
		bala_ggnuc_section_type_type_id = bala_ggnuc_section_type_get_type_once ();
		g_once_init_leave (&bala_ggnuc_section_type_type_id__volatile, bala_ggnuc_section_type_type_id);
	}
	return bala_ggnuc_section_type_type_id__volatile;
}

