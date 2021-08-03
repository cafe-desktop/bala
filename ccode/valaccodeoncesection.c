/* valaccodeoncesection.c generated by valac, the Vala compiler
 * generated from valaccodeoncesection.vala, do not modify */

/* valaccodeoncesection.vala
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
#include <valagee.h>
#include <glib-object.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

struct _ValaCCodeOnceSectionPrivate {
	gchar* _define;
};

static gint ValaCCodeOnceSection_private_offset;
static gpointer vala_ccode_once_section_parent_class = NULL;

static void vala_ccode_once_section_real_write (ValaCCodeNode* base,
                                         ValaCCodeWriter* writer);
static void vala_ccode_once_section_real_write_declaration (ValaCCodeNode* base,
                                                     ValaCCodeWriter* writer);
static void vala_ccode_once_section_finalize (ValaCCodeNode * obj);
static GType vala_ccode_once_section_get_type_once (void);

static inline gpointer
vala_ccode_once_section_get_instance_private (ValaCCodeOnceSection* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeOnceSection_private_offset);
}

const gchar*
vala_ccode_once_section_get_define (ValaCCodeOnceSection* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_define;
	result = _tmp0_;
	return result;
}

void
vala_ccode_once_section_set_define (ValaCCodeOnceSection* self,
                                    const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_define);
	self->priv->_define = _tmp0_;
}

ValaCCodeOnceSection*
vala_ccode_once_section_construct (GType object_type,
                                   const gchar* def)
{
	ValaCCodeOnceSection* self = NULL;
	g_return_val_if_fail (def != NULL, NULL);
	self = (ValaCCodeOnceSection*) vala_ccode_fragment_construct (object_type);
	vala_ccode_once_section_set_define (self, def);
	return self;
}

ValaCCodeOnceSection*
vala_ccode_once_section_new (const gchar* def)
{
	return vala_ccode_once_section_construct (VALA_TYPE_CCODE_ONCE_SECTION, def);
}

static void
vala_ccode_once_section_real_write (ValaCCodeNode* base,
                                    ValaCCodeWriter* writer)
{
	ValaCCodeOnceSection * self;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	self = (ValaCCodeOnceSection*) base;
	g_return_if_fail (writer != NULL);
	vala_ccode_writer_write_indent (writer, NULL);
	vala_ccode_writer_write_string (writer, "#ifndef ");
	_tmp0_ = self->priv->_define;
	vala_ccode_writer_write_string (writer, _tmp0_);
	vala_ccode_writer_write_newline (writer);
	vala_ccode_writer_write_string (writer, "#define ");
	_tmp1_ = self->priv->_define;
	vala_ccode_writer_write_string (writer, _tmp1_);
	vala_ccode_writer_write_newline (writer);
	{
		ValaList* _node_list = NULL;
		ValaList* _tmp2_;
		gint _node_size = 0;
		ValaList* _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _node_index = 0;
		_tmp2_ = vala_ccode_fragment_get_children ((ValaCCodeFragment*) self);
		_node_list = _tmp2_;
		_tmp3_ = _node_list;
		_tmp4_ = vala_collection_get_size ((ValaCollection*) _tmp3_);
		_tmp5_ = _tmp4_;
		_node_size = _tmp5_;
		_node_index = -1;
		while (TRUE) {
			gint _tmp6_;
			gint _tmp7_;
			ValaCCodeNode* node = NULL;
			ValaList* _tmp8_;
			gpointer _tmp9_;
			ValaCCodeNode* _tmp10_;
			_node_index = _node_index + 1;
			_tmp6_ = _node_index;
			_tmp7_ = _node_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _node_list;
			_tmp9_ = vala_list_get (_tmp8_, _node_index);
			node = (ValaCCodeNode*) _tmp9_;
			_tmp10_ = node;
			vala_ccode_node_write_combined (_tmp10_, writer);
			_vala_ccode_node_unref0 (node);
		}
		_vala_iterable_unref0 (_node_list);
	}
	vala_ccode_writer_write_indent (writer, NULL);
	vala_ccode_writer_write_string (writer, "#endif");
	vala_ccode_writer_write_newline (writer);
}

static void
vala_ccode_once_section_real_write_declaration (ValaCCodeNode* base,
                                                ValaCCodeWriter* writer)
{
	ValaCCodeOnceSection * self;
	self = (ValaCCodeOnceSection*) base;
	g_return_if_fail (writer != NULL);
}

static void
vala_ccode_once_section_class_init (ValaCCodeOnceSectionClass * klass,
                                    gpointer klass_data)
{
	vala_ccode_once_section_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_once_section_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeOnceSection_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_once_section_real_write;
	((ValaCCodeNodeClass *) klass)->write_declaration = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_once_section_real_write_declaration;
}

static void
vala_ccode_once_section_instance_init (ValaCCodeOnceSection * self,
                                       gpointer klass)
{
	self->priv = vala_ccode_once_section_get_instance_private (self);
}

static void
vala_ccode_once_section_finalize (ValaCCodeNode * obj)
{
	ValaCCodeOnceSection * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_ONCE_SECTION, ValaCCodeOnceSection);
	_g_free0 (self->priv->_define);
	VALA_CCODE_NODE_CLASS (vala_ccode_once_section_parent_class)->finalize (obj);
}

/**
 * Represents a section that should only to processed once.
 */
static GType
vala_ccode_once_section_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeOnceSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_once_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeOnceSection), 0, (GInstanceInitFunc) vala_ccode_once_section_instance_init, NULL };
	GType vala_ccode_once_section_type_id;
	vala_ccode_once_section_type_id = g_type_register_static (VALA_TYPE_CCODE_FRAGMENT, "ValaCCodeOnceSection", &g_define_type_info, 0);
	ValaCCodeOnceSection_private_offset = g_type_add_instance_private (vala_ccode_once_section_type_id, sizeof (ValaCCodeOnceSectionPrivate));
	return vala_ccode_once_section_type_id;
}

GType
vala_ccode_once_section_get_type (void)
{
	static volatile gsize vala_ccode_once_section_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_once_section_type_id__volatile)) {
		GType vala_ccode_once_section_type_id;
		vala_ccode_once_section_type_id = vala_ccode_once_section_get_type_once ();
		g_once_init_leave (&vala_ccode_once_section_type_id__volatile, vala_ccode_once_section_type_id);
	}
	return vala_ccode_once_section_type_id__volatile;
}

