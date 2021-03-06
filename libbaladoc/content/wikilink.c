/* wikilink.c generated by balac, the Bala compiler
 * generated from wikilink.bala, do not modify */

/* link.bala
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

#include "baladoc.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <balagee.h>
#include <glib-object.h>

enum  {
	BALADOC_CONTENT_WIKI_LINK_0_PROPERTY,
	BALADOC_CONTENT_WIKI_LINK_PAGE_PROPERTY,
	BALADOC_CONTENT_WIKI_LINK_NAME_PROPERTY,
	BALADOC_CONTENT_WIKI_LINK_NUM_PROPERTIES
};
static GParamSpec* baladoc_content_wiki_link_properties[BALADOC_CONTENT_WIKI_LINK_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))

struct _BaladocContentWikiLinkPrivate {
	BaladocWikiPage* _page;
	gchar* _name;
};

static gint BaladocContentWikiLink_private_offset;
static gpointer baladoc_content_wiki_link_parent_class = NULL;
static BaladocContentInlineIface * baladoc_content_wiki_link_baladoc_content_inline_parent_iface = NULL;

G_GNUC_INTERNAL void baladoc_content_wiki_link_set_page (BaladocContentWikiLink* self,
                                         BaladocWikiPage* value);
G_GNUC_INTERNAL BaladocContentWikiLink* baladoc_content_wiki_link_new (void);
G_GNUC_INTERNAL BaladocContentWikiLink* baladoc_content_wiki_link_construct (GType object_type);
G_GNUC_INTERNAL BaladocContentInlineContent* baladoc_content_inline_content_construct (GType object_type);
static void baladoc_content_wiki_link_real_check (BaladocContentContentElement* base,
                                           BaladocApiTree* api_root,
                                           BaladocApiNode* container,
                                           const gchar* file_path,
                                           BaladocErrorReporter* reporter,
                                           BaladocSettings* settings);
static void baladoc_content_wiki_link_real_accept (BaladocContentContentElement* base,
                                            BaladocContentContentVisitor* visitor);
static gboolean baladoc_content_wiki_link_real_is_empty (BaladocContentContentElement* base);
static BaladocContentContentElement* baladoc_content_wiki_link_real_copy (BaladocContentContentElement* base,
                                                                   BaladocContentContentElement* new_parent);
G_GNUC_INTERNAL void baladoc_content_content_element_set_parent (BaladocContentContentElement* self,
                                                 BaladocContentContentElement* value);
static void baladoc_content_wiki_link_finalize (GObject * obj);
static GType baladoc_content_wiki_link_get_type_once (void);
static void _bala_baladoc_content_wiki_link_get_property (GObject * object,
                                                   guint property_id,
                                                   GValue * value,
                                                   GParamSpec * pspec);
static void _bala_baladoc_content_wiki_link_set_property (GObject * object,
                                                   guint property_id,
                                                   const GValue * value,
                                                   GParamSpec * pspec);

static inline gpointer
baladoc_content_wiki_link_get_instance_private (BaladocContentWikiLink* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocContentWikiLink_private_offset);
}

BaladocWikiPage*
baladoc_content_wiki_link_get_page (BaladocContentWikiLink* self)
{
	BaladocWikiPage* result;
	BaladocWikiPage* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_page;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

G_GNUC_INTERNAL void
baladoc_content_wiki_link_set_page (BaladocContentWikiLink* self,
                                    BaladocWikiPage* value)
{
	BaladocWikiPage* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_content_wiki_link_get_page (self);
	if (old_value != value) {
		BaladocWikiPage* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_page);
		self->priv->_page = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_content_wiki_link_properties[BALADOC_CONTENT_WIKI_LINK_PAGE_PROPERTY]);
	}
}

const gchar*
baladoc_content_wiki_link_get_name (BaladocContentWikiLink* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}

void
baladoc_content_wiki_link_set_name (BaladocContentWikiLink* self,
                                    const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_content_wiki_link_get_name (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_name);
		self->priv->_name = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_content_wiki_link_properties[BALADOC_CONTENT_WIKI_LINK_NAME_PROPERTY]);
	}
}

G_GNUC_INTERNAL BaladocContentWikiLink*
baladoc_content_wiki_link_construct (GType object_type)
{
	BaladocContentWikiLink * self = NULL;
	self = (BaladocContentWikiLink*) baladoc_content_inline_content_construct (object_type);
	return self;
}

G_GNUC_INTERNAL BaladocContentWikiLink*
baladoc_content_wiki_link_new (void)
{
	return baladoc_content_wiki_link_construct (BALADOC_CONTENT_TYPE_WIKI_LINK);
}

static void
baladoc_content_wiki_link_real_check (BaladocContentContentElement* base,
                                      BaladocApiTree* api_root,
                                      BaladocApiNode* container,
                                      const gchar* file_path,
                                      BaladocErrorReporter* reporter,
                                      BaladocSettings* settings)
{
	BaladocContentWikiLink * self;
	BaladocWikiPageTree* _tmp0_;
	BaladocWikiPageTree* _tmp1_;
	const gchar* _tmp2_;
	BaladocWikiPage* _tmp3_;
	BaladocWikiPage* _tmp4_;
	BaladocWikiPage* _tmp5_;
	self = (BaladocContentWikiLink*) base;
	g_return_if_fail (api_root != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (file_path != NULL);
	g_return_if_fail (reporter != NULL);
	g_return_if_fail (settings != NULL);
	BALADOC_CONTENT_CONTENT_ELEMENT_CLASS (baladoc_content_wiki_link_parent_class)->check ((BaladocContentContentElement*) G_TYPE_CHECK_INSTANCE_CAST (self, BALADOC_CONTENT_TYPE_INLINE_CONTENT, BaladocContentInlineContent), api_root, container, file_path, reporter, settings);
	_tmp0_ = baladoc_api_tree_get_wikitree (api_root);
	_tmp1_ = _tmp0_;
	_tmp2_ = self->priv->_name;
	_tmp3_ = baladoc_wiki_page_tree_search (_tmp1_, _tmp2_);
	_tmp4_ = _tmp3_;
	baladoc_content_wiki_link_set_page (self, _tmp4_);
	_g_object_unref0 (_tmp4_);
	_tmp5_ = self->priv->_page;
	if (_tmp5_ == NULL) {
		gchar* _tmp6_ = NULL;
		gchar* node_segment = NULL;
		gchar* _tmp11_;
		const gchar* _tmp12_;
		gchar* _tmp13_;
		gchar* _tmp14_;
		const gchar* _tmp15_;
		if (BALADOC_API_IS_PACKAGE (container)) {
			gchar* _tmp7_;
			_tmp7_ = g_strdup ("");
			_g_free0 (_tmp6_);
			_tmp6_ = _tmp7_;
		} else {
			gchar* _tmp8_;
			gchar* _tmp9_;
			gchar* _tmp10_;
			_tmp8_ = baladoc_api_node_get_full_name (container);
			_tmp9_ = _tmp8_;
			_tmp10_ = g_strconcat (_tmp9_, ": ", NULL);
			_g_free0 (_tmp6_);
			_tmp6_ = _tmp10_;
			_g_free0 (_tmp9_);
		}
		_tmp11_ = g_strdup (_tmp6_);
		node_segment = _tmp11_;
		_tmp12_ = node_segment;
		_tmp13_ = g_strdup_printf ("%s: %s[[", file_path, _tmp12_);
		_tmp14_ = _tmp13_;
		_tmp15_ = self->priv->_name;
		baladoc_error_reporter_simple_warning (reporter, _tmp14_, "'%s' does not exist", _tmp15_);
		_g_free0 (_tmp14_);
		_g_free0 (node_segment);
		_g_free0 (_tmp6_);
		return;
	}
}

static void
baladoc_content_wiki_link_real_accept (BaladocContentContentElement* base,
                                       BaladocContentContentVisitor* visitor)
{
	BaladocContentWikiLink * self;
	self = (BaladocContentWikiLink*) base;
	g_return_if_fail (visitor != NULL);
	baladoc_content_content_visitor_visit_wiki_link (visitor, self);
}

static gboolean
baladoc_content_wiki_link_real_is_empty (BaladocContentContentElement* base)
{
	BaladocContentWikiLink * self;
	gboolean result = FALSE;
	self = (BaladocContentWikiLink*) base;
	result = FALSE;
	return result;
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static BaladocContentContentElement*
baladoc_content_wiki_link_real_copy (BaladocContentContentElement* base,
                                     BaladocContentContentElement* new_parent)
{
	BaladocContentWikiLink * self;
	BaladocContentWikiLink* link = NULL;
	BaladocContentWikiLink* _tmp0_;
	BaladocContentWikiLink* _tmp1_;
	BaladocContentWikiLink* _tmp2_;
	BaladocWikiPage* _tmp3_;
	BaladocContentWikiLink* _tmp4_;
	const gchar* _tmp5_;
	BaladocContentContentElement* result = NULL;
	self = (BaladocContentWikiLink*) base;
	_tmp0_ = baladoc_content_wiki_link_new ();
	link = _tmp0_;
	_tmp1_ = link;
	baladoc_content_content_element_set_parent ((BaladocContentContentElement*) _tmp1_, new_parent);
	_tmp2_ = link;
	_tmp3_ = self->priv->_page;
	baladoc_content_wiki_link_set_page (_tmp2_, _tmp3_);
	_tmp4_ = link;
	_tmp5_ = self->priv->_name;
	baladoc_content_wiki_link_set_name (_tmp4_, _tmp5_);
	{
		BalaList* _element_list = NULL;
		BalaList* _tmp6_;
		BalaList* _tmp7_;
		BalaList* _tmp8_;
		gint _element_size = 0;
		BalaList* _tmp9_;
		gint _tmp10_;
		gint _tmp11_;
		gint _element_index = 0;
		_tmp6_ = baladoc_content_inline_content_get_content ((BaladocContentInlineContent*) self);
		_tmp7_ = _tmp6_;
		_tmp8_ = _bala_iterable_ref0 (_tmp7_);
		_element_list = _tmp8_;
		_tmp9_ = _element_list;
		_tmp10_ = bala_collection_get_size ((BalaCollection*) _tmp9_);
		_tmp11_ = _tmp10_;
		_element_size = _tmp11_;
		_element_index = -1;
		while (TRUE) {
			gint _tmp12_;
			gint _tmp13_;
			BaladocContentInline* element = NULL;
			BalaList* _tmp14_;
			gpointer _tmp15_;
			BaladocContentInline* copy = NULL;
			BaladocContentInline* _tmp16_;
			BaladocContentWikiLink* _tmp17_;
			BaladocContentContentElement* _tmp18_;
			BaladocContentInline* _tmp19_;
			BaladocContentWikiLink* _tmp20_;
			BalaList* _tmp21_;
			BalaList* _tmp22_;
			BaladocContentInline* _tmp23_;
			_element_index = _element_index + 1;
			_tmp12_ = _element_index;
			_tmp13_ = _element_size;
			if (!(_tmp12_ < _tmp13_)) {
				break;
			}
			_tmp14_ = _element_list;
			_tmp15_ = bala_list_get (_tmp14_, _element_index);
			element = (BaladocContentInline*) _tmp15_;
			_tmp16_ = element;
			_tmp17_ = link;
			_tmp18_ = baladoc_content_content_element_copy ((BaladocContentContentElement*) _tmp16_, (BaladocContentContentElement*) _tmp17_);
			_tmp19_ = BALADOC_CONTENT_IS_INLINE (_tmp18_) ? ((BaladocContentInline*) _tmp18_) : NULL;
			if (_tmp19_ == NULL) {
				_g_object_unref0 (_tmp18_);
			}
			copy = _tmp19_;
			_tmp20_ = link;
			_tmp21_ = baladoc_content_inline_content_get_content ((BaladocContentInlineContent*) _tmp20_);
			_tmp22_ = _tmp21_;
			_tmp23_ = copy;
			bala_collection_add ((BalaCollection*) _tmp22_, _tmp23_);
			_g_object_unref0 (copy);
			_g_object_unref0 (element);
		}
		_bala_iterable_unref0 (_element_list);
	}
	result = (BaladocContentContentElement*) link;
	return result;
}

static void
baladoc_content_wiki_link_class_init (BaladocContentWikiLinkClass * klass,
                                      gpointer klass_data)
{
	baladoc_content_wiki_link_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &BaladocContentWikiLink_private_offset);
	((BaladocContentContentElementClass *) klass)->check = (void (*) (BaladocContentContentElement*, BaladocApiTree*, BaladocApiNode*, const gchar*, BaladocErrorReporter*, BaladocSettings*)) baladoc_content_wiki_link_real_check;
	((BaladocContentContentElementClass *) klass)->accept = (void (*) (BaladocContentContentElement*, BaladocContentContentVisitor*)) baladoc_content_wiki_link_real_accept;
	((BaladocContentContentElementClass *) klass)->is_empty = (gboolean (*) (BaladocContentContentElement*)) baladoc_content_wiki_link_real_is_empty;
	((BaladocContentContentElementClass *) klass)->copy = (BaladocContentContentElement* (*) (BaladocContentContentElement*, BaladocContentContentElement*)) baladoc_content_wiki_link_real_copy;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_content_wiki_link_get_property;
	G_OBJECT_CLASS (klass)->set_property = _bala_baladoc_content_wiki_link_set_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_content_wiki_link_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_CONTENT_WIKI_LINK_PAGE_PROPERTY, baladoc_content_wiki_link_properties[BALADOC_CONTENT_WIKI_LINK_PAGE_PROPERTY] = g_param_spec_object ("page", "page", "page", BALADOC_TYPE_WIKI_PAGE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_CONTENT_WIKI_LINK_NAME_PROPERTY, baladoc_content_wiki_link_properties[BALADOC_CONTENT_WIKI_LINK_NAME_PROPERTY] = g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
}

static void
baladoc_content_wiki_link_baladoc_content_inline_interface_init (BaladocContentInlineIface * iface,
                                                                 gpointer iface_data)
{
	baladoc_content_wiki_link_baladoc_content_inline_parent_iface = g_type_interface_peek_parent (iface);
}

static void
baladoc_content_wiki_link_instance_init (BaladocContentWikiLink * self,
                                         gpointer klass)
{
	self->priv = baladoc_content_wiki_link_get_instance_private (self);
}

static void
baladoc_content_wiki_link_finalize (GObject * obj)
{
	BaladocContentWikiLink * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_CONTENT_TYPE_WIKI_LINK, BaladocContentWikiLink);
	_g_object_unref0 (self->priv->_page);
	_g_free0 (self->priv->_name);
	G_OBJECT_CLASS (baladoc_content_wiki_link_parent_class)->finalize (obj);
}

static GType
baladoc_content_wiki_link_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocContentWikiLinkClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_content_wiki_link_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocContentWikiLink), 0, (GInstanceInitFunc) baladoc_content_wiki_link_instance_init, NULL };
	static const GInterfaceInfo baladoc_content_inline_info = { (GInterfaceInitFunc) baladoc_content_wiki_link_baladoc_content_inline_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType baladoc_content_wiki_link_type_id;
	baladoc_content_wiki_link_type_id = g_type_register_static (BALADOC_CONTENT_TYPE_INLINE_CONTENT, "BaladocContentWikiLink", &g_define_type_info, 0);
	g_type_add_interface_static (baladoc_content_wiki_link_type_id, BALADOC_CONTENT_TYPE_INLINE, &baladoc_content_inline_info);
	BaladocContentWikiLink_private_offset = g_type_add_instance_private (baladoc_content_wiki_link_type_id, sizeof (BaladocContentWikiLinkPrivate));
	return baladoc_content_wiki_link_type_id;
}

GType
baladoc_content_wiki_link_get_type (void)
{
	static volatile gsize baladoc_content_wiki_link_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_content_wiki_link_type_id__volatile)) {
		GType baladoc_content_wiki_link_type_id;
		baladoc_content_wiki_link_type_id = baladoc_content_wiki_link_get_type_once ();
		g_once_init_leave (&baladoc_content_wiki_link_type_id__volatile, baladoc_content_wiki_link_type_id);
	}
	return baladoc_content_wiki_link_type_id__volatile;
}

static void
_bala_baladoc_content_wiki_link_get_property (GObject * object,
                                              guint property_id,
                                              GValue * value,
                                              GParamSpec * pspec)
{
	BaladocContentWikiLink * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_CONTENT_TYPE_WIKI_LINK, BaladocContentWikiLink);
	switch (property_id) {
		case BALADOC_CONTENT_WIKI_LINK_PAGE_PROPERTY:
		g_value_set_object (value, baladoc_content_wiki_link_get_page (self));
		break;
		case BALADOC_CONTENT_WIKI_LINK_NAME_PROPERTY:
		g_value_set_string (value, baladoc_content_wiki_link_get_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_bala_baladoc_content_wiki_link_set_property (GObject * object,
                                              guint property_id,
                                              const GValue * value,
                                              GParamSpec * pspec)
{
	BaladocContentWikiLink * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_CONTENT_TYPE_WIKI_LINK, BaladocContentWikiLink);
	switch (property_id) {
		case BALADOC_CONTENT_WIKI_LINK_PAGE_PROPERTY:
		baladoc_content_wiki_link_set_page (self, g_value_get_object (value));
		break;
		case BALADOC_CONTENT_WIKI_LINK_NAME_PROPERTY:
		baladoc_content_wiki_link_set_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

