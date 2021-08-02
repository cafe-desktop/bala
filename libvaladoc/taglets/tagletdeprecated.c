/* tagletdeprecated.c generated by valac, the Vala compiler
 * generated from tagletdeprecated.vala, do not modify */

/* tagletdeprecated.vala
 *
 * Copyright (C) 2008-2009 Didier Villevalois
 * Copyright (C) 2008-2012 Florian Brosch
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Didier 'Ptitjes Villevalois <ptitjes@free.fr>
 */

#include "valadoc.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <valagee.h>
#include <glib-object.h>

enum  {
	VALADOC_TAGLETS_DEPRECATED_0_PROPERTY,
	VALADOC_TAGLETS_DEPRECATED_NUM_PROPERTIES
};
static GParamSpec* valadoc_taglets_deprecated_properties[VALADOC_TAGLETS_DEPRECATED_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

static gpointer valadoc_taglets_deprecated_parent_class = NULL;
static ValadocContentTagletIface * valadoc_taglets_deprecated_valadoc_content_taglet_parent_iface = NULL;
static ValadocContentBlockIface * valadoc_taglets_deprecated_valadoc_content_block_parent_iface = NULL;

static ValadocRule* valadoc_taglets_deprecated_real_get_parser_rule (ValadocContentTaglet* base,
                                                              ValadocRule* run_rule);
static void valadoc_taglets_deprecated_real_check (ValadocContentContentElement* base,
                                            ValadocApiTree* api_root,
                                            ValadocApiNode* container,
                                            const gchar* file_path,
                                            ValadocErrorReporter* reporter,
                                            ValadocSettings* settings);
static void valadoc_taglets_deprecated_real_accept (ValadocContentContentElement* base,
                                             ValadocContentContentVisitor* visitor);
static gboolean valadoc_taglets_deprecated_real_is_empty (ValadocContentContentElement* base);
static ValadocContentContentElement* valadoc_taglets_deprecated_real_copy (ValadocContentContentElement* base,
                                                                    ValadocContentContentElement* new_parent);
G_GNUC_INTERNAL void valadoc_content_content_element_set_parent (ValadocContentContentElement* self,
                                                 ValadocContentContentElement* value);
G_GNUC_INTERNAL ValadocContentBlockContent* valadoc_content_block_content_construct (GType object_type);
static GType valadoc_taglets_deprecated_get_type_once (void);

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static ValadocRule*
valadoc_taglets_deprecated_real_get_parser_rule (ValadocContentTaglet* base,
                                                 ValadocRule* run_rule)
{
	ValadocTagletsDeprecated * self;
	ValadocRule* _tmp0_;
	ValadocRule* result = NULL;
	self = (ValadocTagletsDeprecated*) base;
	g_return_val_if_fail (run_rule != NULL, NULL);
	_tmp0_ = _g_object_ref0 (run_rule);
	result = _tmp0_;
	return result;
}

static void
valadoc_taglets_deprecated_real_check (ValadocContentContentElement* base,
                                       ValadocApiTree* api_root,
                                       ValadocApiNode* container,
                                       const gchar* file_path,
                                       ValadocErrorReporter* reporter,
                                       ValadocSettings* settings)
{
	ValadocTagletsDeprecated * self;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	self = (ValadocTagletsDeprecated*) base;
	g_return_if_fail (api_root != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (file_path != NULL);
	g_return_if_fail (reporter != NULL);
	g_return_if_fail (settings != NULL);
	VALADOC_CONTENT_CONTENT_ELEMENT_CLASS (valadoc_taglets_deprecated_parent_class)->check ((ValadocContentContentElement*) G_TYPE_CHECK_INSTANCE_CAST (self, VALADOC_CONTENT_TYPE_BLOCK_CONTENT, ValadocContentBlockContent), api_root, container, file_path, reporter, settings);
	_tmp0_ = valadoc_api_node_get_full_name (container);
	_tmp1_ = _tmp0_;
	_tmp2_ = g_strdup_printf ("%s: %s: @deprecated", file_path, _tmp1_);
	_tmp3_ = _tmp2_;
	valadoc_error_reporter_simple_warning (reporter, _tmp3_, "@deprecated is deprecated. Use [Version (deprecated = true)]");
	_g_free0 (_tmp3_);
	_g_free0 (_tmp1_);
}

static void
valadoc_taglets_deprecated_real_accept (ValadocContentContentElement* base,
                                        ValadocContentContentVisitor* visitor)
{
	ValadocTagletsDeprecated * self;
	self = (ValadocTagletsDeprecated*) base;
	g_return_if_fail (visitor != NULL);
	valadoc_content_content_visitor_visit_taglet (visitor, (ValadocContentTaglet*) self);
}

static gboolean
valadoc_taglets_deprecated_real_is_empty (ValadocContentContentElement* base)
{
	ValadocTagletsDeprecated * self;
	gboolean result = FALSE;
	self = (ValadocTagletsDeprecated*) base;
	result = FALSE;
	return result;
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static ValadocContentContentElement*
valadoc_taglets_deprecated_real_copy (ValadocContentContentElement* base,
                                      ValadocContentContentElement* new_parent)
{
	ValadocTagletsDeprecated * self;
	ValadocTagletsDeprecated* deprecated = NULL;
	ValadocTagletsDeprecated* _tmp0_;
	ValadocTagletsDeprecated* _tmp1_;
	ValadocContentContentElement* result = NULL;
	self = (ValadocTagletsDeprecated*) base;
	_tmp0_ = valadoc_taglets_deprecated_new ();
	deprecated = _tmp0_;
	_tmp1_ = deprecated;
	valadoc_content_content_element_set_parent ((ValadocContentContentElement*) _tmp1_, new_parent);
	{
		ValaList* _element_list = NULL;
		ValaList* _tmp2_;
		ValaList* _tmp3_;
		ValaList* _tmp4_;
		gint _element_size = 0;
		ValaList* _tmp5_;
		gint _tmp6_;
		gint _tmp7_;
		gint _element_index = 0;
		_tmp2_ = valadoc_content_block_content_get_content ((ValadocContentBlockContent*) self);
		_tmp3_ = _tmp2_;
		_tmp4_ = _vala_iterable_ref0 (_tmp3_);
		_element_list = _tmp4_;
		_tmp5_ = _element_list;
		_tmp6_ = vala_collection_get_size ((ValaCollection*) _tmp5_);
		_tmp7_ = _tmp6_;
		_element_size = _tmp7_;
		_element_index = -1;
		while (TRUE) {
			gint _tmp8_;
			gint _tmp9_;
			ValadocContentBlock* element = NULL;
			ValaList* _tmp10_;
			gpointer _tmp11_;
			ValadocContentBlock* copy = NULL;
			ValadocContentBlock* _tmp12_;
			ValadocTagletsDeprecated* _tmp13_;
			ValadocContentContentElement* _tmp14_;
			ValadocContentBlock* _tmp15_;
			ValadocTagletsDeprecated* _tmp16_;
			ValaList* _tmp17_;
			ValaList* _tmp18_;
			ValadocContentBlock* _tmp19_;
			_element_index = _element_index + 1;
			_tmp8_ = _element_index;
			_tmp9_ = _element_size;
			if (!(_tmp8_ < _tmp9_)) {
				break;
			}
			_tmp10_ = _element_list;
			_tmp11_ = vala_list_get (_tmp10_, _element_index);
			element = (ValadocContentBlock*) _tmp11_;
			_tmp12_ = element;
			_tmp13_ = deprecated;
			_tmp14_ = valadoc_content_content_element_copy ((ValadocContentContentElement*) _tmp12_, (ValadocContentContentElement*) _tmp13_);
			_tmp15_ = VALADOC_CONTENT_IS_BLOCK (_tmp14_) ? ((ValadocContentBlock*) _tmp14_) : NULL;
			if (_tmp15_ == NULL) {
				_g_object_unref0 (_tmp14_);
			}
			copy = _tmp15_;
			_tmp16_ = deprecated;
			_tmp17_ = valadoc_content_block_content_get_content ((ValadocContentBlockContent*) _tmp16_);
			_tmp18_ = _tmp17_;
			_tmp19_ = copy;
			vala_collection_add ((ValaCollection*) _tmp18_, _tmp19_);
			_g_object_unref0 (copy);
			_g_object_unref0 (element);
		}
		_vala_iterable_unref0 (_element_list);
	}
	result = (ValadocContentContentElement*) deprecated;
	return result;
}

ValadocTagletsDeprecated*
valadoc_taglets_deprecated_construct (GType object_type)
{
	ValadocTagletsDeprecated * self = NULL;
	self = (ValadocTagletsDeprecated*) valadoc_content_block_content_construct (object_type);
	return self;
}

ValadocTagletsDeprecated*
valadoc_taglets_deprecated_new (void)
{
	return valadoc_taglets_deprecated_construct (VALADOC_TAGLETS_TYPE_DEPRECATED);
}

static void
valadoc_taglets_deprecated_class_init (ValadocTagletsDeprecatedClass * klass,
                                       gpointer klass_data)
{
	valadoc_taglets_deprecated_parent_class = g_type_class_peek_parent (klass);
	((ValadocContentContentElementClass *) klass)->check = (void (*) (ValadocContentContentElement*, ValadocApiTree*, ValadocApiNode*, const gchar*, ValadocErrorReporter*, ValadocSettings*)) valadoc_taglets_deprecated_real_check;
	((ValadocContentContentElementClass *) klass)->accept = (void (*) (ValadocContentContentElement*, ValadocContentContentVisitor*)) valadoc_taglets_deprecated_real_accept;
	((ValadocContentContentElementClass *) klass)->is_empty = (gboolean (*) (ValadocContentContentElement*)) valadoc_taglets_deprecated_real_is_empty;
	((ValadocContentContentElementClass *) klass)->copy = (ValadocContentContentElement* (*) (ValadocContentContentElement*, ValadocContentContentElement*)) valadoc_taglets_deprecated_real_copy;
}

static void
valadoc_taglets_deprecated_valadoc_content_taglet_interface_init (ValadocContentTagletIface * iface,
                                                                  gpointer iface_data)
{
	valadoc_taglets_deprecated_valadoc_content_taglet_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_parser_rule = (ValadocRule* (*) (ValadocContentTaglet*, ValadocRule*)) valadoc_taglets_deprecated_real_get_parser_rule;
}

static void
valadoc_taglets_deprecated_valadoc_content_block_interface_init (ValadocContentBlockIface * iface,
                                                                 gpointer iface_data)
{
	valadoc_taglets_deprecated_valadoc_content_block_parent_iface = g_type_interface_peek_parent (iface);
}

static void
valadoc_taglets_deprecated_instance_init (ValadocTagletsDeprecated * self,
                                          gpointer klass)
{
}

static GType
valadoc_taglets_deprecated_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocTagletsDeprecatedClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_taglets_deprecated_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocTagletsDeprecated), 0, (GInstanceInitFunc) valadoc_taglets_deprecated_instance_init, NULL };
	static const GInterfaceInfo valadoc_content_taglet_info = { (GInterfaceInitFunc) valadoc_taglets_deprecated_valadoc_content_taglet_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	static const GInterfaceInfo valadoc_content_block_info = { (GInterfaceInitFunc) valadoc_taglets_deprecated_valadoc_content_block_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType valadoc_taglets_deprecated_type_id;
	valadoc_taglets_deprecated_type_id = g_type_register_static (VALADOC_CONTENT_TYPE_BLOCK_CONTENT, "ValadocTagletsDeprecated", &g_define_type_info, 0);
	g_type_add_interface_static (valadoc_taglets_deprecated_type_id, VALADOC_CONTENT_TYPE_TAGLET, &valadoc_content_taglet_info);
	g_type_add_interface_static (valadoc_taglets_deprecated_type_id, VALADOC_CONTENT_TYPE_BLOCK, &valadoc_content_block_info);
	return valadoc_taglets_deprecated_type_id;
}

GType
valadoc_taglets_deprecated_get_type (void)
{
	static volatile gsize valadoc_taglets_deprecated_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_taglets_deprecated_type_id__volatile)) {
		GType valadoc_taglets_deprecated_type_id;
		valadoc_taglets_deprecated_type_id = valadoc_taglets_deprecated_get_type_once ();
		g_once_init_leave (&valadoc_taglets_deprecated_type_id__volatile, valadoc_taglets_deprecated_type_id);
	}
	return valadoc_taglets_deprecated_type_id__volatile;
}

