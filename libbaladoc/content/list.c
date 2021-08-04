/* list.c generated by balac, the Vala compiler
 * generated from list.bala, do not modify */

/* list.bala
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
#include <balagee.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

enum  {
	BALADOC_CONTENT_LIST_0_PROPERTY,
	BALADOC_CONTENT_LIST_BULLET_PROPERTY,
	BALADOC_CONTENT_LIST_ITEMS_PROPERTY,
	BALADOC_CONTENT_LIST_NUM_PROPERTIES
};
static GParamSpec* baladoc_content_list_properties[BALADOC_CONTENT_LIST_NUM_PROPERTIES];
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _bala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _bala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _bala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _bala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _ValadocContentListPrivate {
	ValadocContentListBullet _bullet;
	ValaList* _items;
};

static gint ValadocContentList_private_offset;
static gpointer baladoc_content_list_parent_class = NULL;
static ValadocContentBlockIface * baladoc_content_list_baladoc_content_block_parent_iface = NULL;

static ValadocContentListBullet* _baladoc_content_list_bullet_dup (ValadocContentListBullet* self);
G_GNUC_INTERNAL ValadocContentList* baladoc_content_list_new (void);
G_GNUC_INTERNAL ValadocContentList* baladoc_content_list_construct (GType object_type);
static void baladoc_content_list_real_check (ValadocContentContentElement* base,
                                      ValadocApiTree* api_root,
                                      ValadocApiNode* container,
                                      const gchar* file_path,
                                      ValadocErrorReporter* reporter,
                                      ValadocSettings* settings);
G_GNUC_INTERNAL void baladoc_content_content_element_set_parent (ValadocContentContentElement* self,
                                                 ValadocContentContentElement* value);
static void baladoc_content_list_real_accept (ValadocContentContentElement* base,
                                       ValadocContentContentVisitor* visitor);
static void baladoc_content_list_real_accept_children (ValadocContentContentElement* base,
                                                ValadocContentContentVisitor* visitor);
static gboolean baladoc_content_list_real_is_empty (ValadocContentContentElement* base);
static ValadocContentContentElement* baladoc_content_list_real_copy (ValadocContentContentElement* base,
                                                              ValadocContentContentElement* new_parent);
static void baladoc_content_list_finalize (GObject * obj);
static GType baladoc_content_list_get_type_once (void);
static void _bala_baladoc_content_list_get_property (GObject * object,
                                              guint property_id,
                                              GValue * value,
                                              GParamSpec * pspec);
static void _bala_baladoc_content_list_set_property (GObject * object,
                                              guint property_id,
                                              const GValue * value,
                                              GParamSpec * pspec);

static inline gpointer
baladoc_content_list_get_instance_private (ValadocContentList* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocContentList_private_offset);
}

static ValadocContentListBullet*
_baladoc_content_list_bullet_dup (ValadocContentListBullet* self)
{
	ValadocContentListBullet* dup;
	dup = g_new0 (ValadocContentListBullet, 1);
	memcpy (dup, self, sizeof (ValadocContentListBullet));
	return dup;
}

static gpointer
__baladoc_content_list_bullet_dup0 (gpointer self)
{
	return self ? _baladoc_content_list_bullet_dup (self) : NULL;
}

ValadocContentListBullet*
baladoc_content_list_bullet_from_string (const gchar* str)
{
	const gchar* _tmp0_;
	GQuark _tmp2_ = 0U;
	static GQuark _tmp1_label0 = 0;
	static GQuark _tmp1_label1 = 0;
	static GQuark _tmp1_label2 = 0;
	static GQuark _tmp1_label3 = 0;
	static GQuark _tmp1_label4 = 0;
	static GQuark _tmp1_label5 = 0;
	static GQuark _tmp1_label6 = 0;
	static GQuark _tmp1_label7 = 0;
	ValadocContentListBullet* result = NULL;
	_tmp0_ = str;
	_tmp2_ = (NULL == _tmp0_) ? 0 : g_quark_from_string (_tmp0_);
	if (_tmp2_ == ((0 != _tmp1_label0) ? _tmp1_label0 : (_tmp1_label0 = g_quark_from_static_string ("none")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp3_;
				ValadocContentListBullet* _tmp4_;
				_tmp3_ = BALADOC_CONTENT_LIST_BULLET_NONE;
				_tmp4_ = __baladoc_content_list_bullet_dup0 (&_tmp3_);
				result = _tmp4_;
				return result;
			}
		}
	} else if (_tmp2_ == ((0 != _tmp1_label1) ? _tmp1_label1 : (_tmp1_label1 = g_quark_from_static_string ("unordered")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp5_;
				ValadocContentListBullet* _tmp6_;
				_tmp5_ = BALADOC_CONTENT_LIST_BULLET_UNORDERED;
				_tmp6_ = __baladoc_content_list_bullet_dup0 (&_tmp5_);
				result = _tmp6_;
				return result;
			}
		}
	} else if (_tmp2_ == ((0 != _tmp1_label2) ? _tmp1_label2 : (_tmp1_label2 = g_quark_from_static_string ("ordered")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp7_;
				ValadocContentListBullet* _tmp8_;
				_tmp7_ = BALADOC_CONTENT_LIST_BULLET_ORDERED;
				_tmp8_ = __baladoc_content_list_bullet_dup0 (&_tmp7_);
				result = _tmp8_;
				return result;
			}
		}
	} else if (_tmp2_ == ((0 != _tmp1_label3) ? _tmp1_label3 : (_tmp1_label3 = g_quark_from_static_string ("ordered-number")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp9_;
				ValadocContentListBullet* _tmp10_;
				_tmp9_ = BALADOC_CONTENT_LIST_BULLET_ORDERED_NUMBER;
				_tmp10_ = __baladoc_content_list_bullet_dup0 (&_tmp9_);
				result = _tmp10_;
				return result;
			}
		}
	} else if (_tmp2_ == ((0 != _tmp1_label4) ? _tmp1_label4 : (_tmp1_label4 = g_quark_from_static_string ("ordered-lower-case-alpa")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp11_;
				ValadocContentListBullet* _tmp12_;
				_tmp11_ = BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ALPHA;
				_tmp12_ = __baladoc_content_list_bullet_dup0 (&_tmp11_);
				result = _tmp12_;
				return result;
			}
		}
	} else if (_tmp2_ == ((0 != _tmp1_label5) ? _tmp1_label5 : (_tmp1_label5 = g_quark_from_static_string ("ordered-upper-case-alpha")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp13_;
				ValadocContentListBullet* _tmp14_;
				_tmp13_ = BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ALPHA;
				_tmp14_ = __baladoc_content_list_bullet_dup0 (&_tmp13_);
				result = _tmp14_;
				return result;
			}
		}
	} else if (_tmp2_ == ((0 != _tmp1_label6) ? _tmp1_label6 : (_tmp1_label6 = g_quark_from_static_string ("ordered-lower-case-roman")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp15_;
				ValadocContentListBullet* _tmp16_;
				_tmp15_ = BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ROMAN;
				_tmp16_ = __baladoc_content_list_bullet_dup0 (&_tmp15_);
				result = _tmp16_;
				return result;
			}
		}
	} else if (_tmp2_ == ((0 != _tmp1_label7) ? _tmp1_label7 : (_tmp1_label7 = g_quark_from_static_string ("ordered-upper-case-roman")))) {
		switch (0) {
			default:
			{
				ValadocContentListBullet _tmp17_;
				ValadocContentListBullet* _tmp18_;
				_tmp17_ = BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ROMAN;
				_tmp18_ = __baladoc_content_list_bullet_dup0 (&_tmp17_);
				result = _tmp18_;
				return result;
			}
		}
	}
	result = NULL;
	return result;
}

const gchar*
baladoc_content_list_bullet_to_string (ValadocContentListBullet self)
{
	const gchar* result = NULL;
	switch (self) {
		case BALADOC_CONTENT_LIST_BULLET_NONE:
		{
			result = "none";
			return result;
		}
		case BALADOC_CONTENT_LIST_BULLET_UNORDERED:
		{
			result = "unordered";
			return result;
		}
		case BALADOC_CONTENT_LIST_BULLET_ORDERED:
		{
			result = "ordered";
			return result;
		}
		case BALADOC_CONTENT_LIST_BULLET_ORDERED_NUMBER:
		{
			result = "ordered-number";
			return result;
		}
		case BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ALPHA:
		{
			result = "ordered-lower-case-alpa";
			return result;
		}
		case BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ALPHA:
		{
			result = "ordered-upper-case-alpha";
			return result;
		}
		case BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ROMAN:
		{
			result = "ordered-lower-case-roman";
			return result;
		}
		case BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ROMAN:
		{
			result = "ordered-upper-case-roman";
			return result;
		}
		default:
		break;
	}
	_bala_assert (TRUE, "true");
	result = "";
	return result;
}

static GType
baladoc_content_list_bullet_get_type_once (void)
{
	static const GEnumValue values[] = {{BALADOC_CONTENT_LIST_BULLET_NONE, "BALADOC_CONTENT_LIST_BULLET_NONE", "none"}, {BALADOC_CONTENT_LIST_BULLET_UNORDERED, "BALADOC_CONTENT_LIST_BULLET_UNORDERED", "unordered"}, {BALADOC_CONTENT_LIST_BULLET_ORDERED, "BALADOC_CONTENT_LIST_BULLET_ORDERED", "ordered"}, {BALADOC_CONTENT_LIST_BULLET_ORDERED_NUMBER, "BALADOC_CONTENT_LIST_BULLET_ORDERED_NUMBER", "ordered-number"}, {BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ALPHA, "BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ALPHA", "ordered-lower-case-alpha"}, {BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ALPHA, "BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ALPHA", "ordered-upper-case-alpha"}, {BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ROMAN, "BALADOC_CONTENT_LIST_BULLET_ORDERED_LOWER_CASE_ROMAN", "ordered-lower-case-roman"}, {BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ROMAN, "BALADOC_CONTENT_LIST_BULLET_ORDERED_UPPER_CASE_ROMAN", "ordered-upper-case-roman"}, {0, NULL, NULL}};
	GType baladoc_content_list_bullet_type_id;
	baladoc_content_list_bullet_type_id = g_enum_register_static ("ValadocContentListBullet", values);
	return baladoc_content_list_bullet_type_id;
}

GType
baladoc_content_list_bullet_get_type (void)
{
	static volatile gsize baladoc_content_list_bullet_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_content_list_bullet_type_id__volatile)) {
		GType baladoc_content_list_bullet_type_id;
		baladoc_content_list_bullet_type_id = baladoc_content_list_bullet_get_type_once ();
		g_once_init_leave (&baladoc_content_list_bullet_type_id__volatile, baladoc_content_list_bullet_type_id);
	}
	return baladoc_content_list_bullet_type_id__volatile;
}

ValadocContentListBullet
baladoc_content_list_get_bullet (ValadocContentList* self)
{
	ValadocContentListBullet result;
	ValadocContentListBullet _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_bullet;
	result = _tmp0_;
	return result;
}

void
baladoc_content_list_set_bullet (ValadocContentList* self,
                                 ValadocContentListBullet value)
{
	ValadocContentListBullet old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_content_list_get_bullet (self);
	if (old_value != value) {
		self->priv->_bullet = value;
		g_object_notify_by_pspec ((GObject *) self, baladoc_content_list_properties[BALADOC_CONTENT_LIST_BULLET_PROPERTY]);
	}
}

ValaList*
baladoc_content_list_get_items (ValadocContentList* self)
{
	ValaList* result;
	ValaList* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_items;
	result = _tmp0_;
	return result;
}

G_GNUC_INTERNAL ValadocContentList*
baladoc_content_list_construct (GType object_type)
{
	ValadocContentList * self = NULL;
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	self = (ValadocContentList*) baladoc_content_content_element_construct (object_type);
	self->priv->_bullet = BALADOC_CONTENT_LIST_BULLET_NONE;
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALADOC_CONTENT_TYPE_LIST_ITEM, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp0_);
	_bala_iterable_unref0 (self->priv->_items);
	self->priv->_items = (ValaList*) _tmp1_;
	return self;
}

G_GNUC_INTERNAL ValadocContentList*
baladoc_content_list_new (void)
{
	return baladoc_content_list_construct (BALADOC_CONTENT_TYPE_LIST);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static void
baladoc_content_list_real_check (ValadocContentContentElement* base,
                                 ValadocApiTree* api_root,
                                 ValadocApiNode* container,
                                 const gchar* file_path,
                                 ValadocErrorReporter* reporter,
                                 ValadocSettings* settings)
{
	ValadocContentList * self;
	self = (ValadocContentList*) base;
	g_return_if_fail (api_root != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (file_path != NULL);
	g_return_if_fail (reporter != NULL);
	g_return_if_fail (settings != NULL);
	{
		ValaList* _element_list = NULL;
		ValaList* _tmp0_;
		ValaList* _tmp1_;
		gint _element_size = 0;
		ValaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _element_index = 0;
		_tmp0_ = self->priv->_items;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_element_list = _tmp1_;
		_tmp2_ = _element_list;
		_tmp3_ = bala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_element_size = _tmp4_;
		_element_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValadocContentListItem* element = NULL;
			ValaList* _tmp7_;
			gpointer _tmp8_;
			ValadocContentListItem* _tmp9_;
			ValadocContentListItem* _tmp10_;
			_element_index = _element_index + 1;
			_tmp5_ = _element_index;
			_tmp6_ = _element_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _element_list;
			_tmp8_ = bala_list_get (_tmp7_, _element_index);
			element = (ValadocContentListItem*) _tmp8_;
			_tmp9_ = element;
			baladoc_content_content_element_set_parent ((ValadocContentContentElement*) _tmp9_, (ValadocContentContentElement*) self);
			_tmp10_ = element;
			baladoc_content_content_element_check ((ValadocContentContentElement*) _tmp10_, api_root, container, file_path, reporter, settings);
			_g_object_unref0 (element);
		}
		_bala_iterable_unref0 (_element_list);
	}
}

static void
baladoc_content_list_real_accept (ValadocContentContentElement* base,
                                  ValadocContentContentVisitor* visitor)
{
	ValadocContentList * self;
	self = (ValadocContentList*) base;
	g_return_if_fail (visitor != NULL);
	baladoc_content_content_visitor_visit_list (visitor, self);
}

static void
baladoc_content_list_real_accept_children (ValadocContentContentElement* base,
                                           ValadocContentContentVisitor* visitor)
{
	ValadocContentList * self;
	self = (ValadocContentList*) base;
	g_return_if_fail (visitor != NULL);
	{
		ValaList* _element_list = NULL;
		ValaList* _tmp0_;
		ValaList* _tmp1_;
		gint _element_size = 0;
		ValaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _element_index = 0;
		_tmp0_ = self->priv->_items;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_element_list = _tmp1_;
		_tmp2_ = _element_list;
		_tmp3_ = bala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_element_size = _tmp4_;
		_element_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValadocContentListItem* element = NULL;
			ValaList* _tmp7_;
			gpointer _tmp8_;
			ValadocContentListItem* _tmp9_;
			_element_index = _element_index + 1;
			_tmp5_ = _element_index;
			_tmp6_ = _element_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _element_list;
			_tmp8_ = bala_list_get (_tmp7_, _element_index);
			element = (ValadocContentListItem*) _tmp8_;
			_tmp9_ = element;
			baladoc_content_content_element_accept ((ValadocContentContentElement*) _tmp9_, visitor);
			_g_object_unref0 (element);
		}
		_bala_iterable_unref0 (_element_list);
	}
}

static gboolean
baladoc_content_list_real_is_empty (ValadocContentContentElement* base)
{
	ValadocContentList * self;
	ValaList* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gboolean result = FALSE;
	self = (ValadocContentList*) base;
	_tmp0_ = self->priv->_items;
	_tmp1_ = bala_collection_get_size ((ValaCollection*) _tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_ == 0;
	return result;
}

static ValadocContentContentElement*
baladoc_content_list_real_copy (ValadocContentContentElement* base,
                                ValadocContentContentElement* new_parent)
{
	ValadocContentList * self;
	ValadocContentList* list = NULL;
	ValadocContentList* _tmp0_;
	ValadocContentList* _tmp1_;
	ValadocContentList* _tmp2_;
	ValadocContentListBullet _tmp3_;
	ValadocContentContentElement* result = NULL;
	self = (ValadocContentList*) base;
	_tmp0_ = baladoc_content_list_new ();
	list = _tmp0_;
	_tmp1_ = list;
	baladoc_content_content_element_set_parent ((ValadocContentContentElement*) _tmp1_, new_parent);
	_tmp2_ = list;
	_tmp3_ = self->priv->_bullet;
	baladoc_content_list_set_bullet (_tmp2_, _tmp3_);
	{
		ValaList* _item_list = NULL;
		ValaList* _tmp4_;
		ValaList* _tmp5_;
		ValaList* _tmp6_;
		gint _item_size = 0;
		ValaList* _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		gint _item_index = 0;
		_tmp4_ = baladoc_content_list_get_items (self);
		_tmp5_ = _tmp4_;
		_tmp6_ = _bala_iterable_ref0 (_tmp5_);
		_item_list = _tmp6_;
		_tmp7_ = _item_list;
		_tmp8_ = bala_collection_get_size ((ValaCollection*) _tmp7_);
		_tmp9_ = _tmp8_;
		_item_size = _tmp9_;
		_item_index = -1;
		while (TRUE) {
			gint _tmp10_;
			gint _tmp11_;
			ValadocContentListItem* item = NULL;
			ValaList* _tmp12_;
			gpointer _tmp13_;
			ValadocContentListItem* copy = NULL;
			ValadocContentListItem* _tmp14_;
			ValadocContentList* _tmp15_;
			ValadocContentContentElement* _tmp16_;
			ValadocContentListItem* _tmp17_;
			ValadocContentList* _tmp18_;
			ValaList* _tmp19_;
			ValaList* _tmp20_;
			ValadocContentListItem* _tmp21_;
			_item_index = _item_index + 1;
			_tmp10_ = _item_index;
			_tmp11_ = _item_size;
			if (!(_tmp10_ < _tmp11_)) {
				break;
			}
			_tmp12_ = _item_list;
			_tmp13_ = bala_list_get (_tmp12_, _item_index);
			item = (ValadocContentListItem*) _tmp13_;
			_tmp14_ = item;
			_tmp15_ = list;
			_tmp16_ = baladoc_content_content_element_copy ((ValadocContentContentElement*) _tmp14_, (ValadocContentContentElement*) _tmp15_);
			_tmp17_ = BALADOC_CONTENT_IS_LIST_ITEM (_tmp16_) ? ((ValadocContentListItem*) _tmp16_) : NULL;
			if (_tmp17_ == NULL) {
				_g_object_unref0 (_tmp16_);
			}
			copy = _tmp17_;
			_tmp18_ = list;
			_tmp19_ = baladoc_content_list_get_items (_tmp18_);
			_tmp20_ = _tmp19_;
			_tmp21_ = copy;
			bala_collection_add ((ValaCollection*) _tmp20_, _tmp21_);
			_g_object_unref0 (copy);
			_g_object_unref0 (item);
		}
		_bala_iterable_unref0 (_item_list);
	}
	result = (ValadocContentContentElement*) list;
	return result;
}

static void
baladoc_content_list_class_init (ValadocContentListClass * klass,
                                 gpointer klass_data)
{
	baladoc_content_list_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocContentList_private_offset);
	((ValadocContentContentElementClass *) klass)->check = (void (*) (ValadocContentContentElement*, ValadocApiTree*, ValadocApiNode*, const gchar*, ValadocErrorReporter*, ValadocSettings*)) baladoc_content_list_real_check;
	((ValadocContentContentElementClass *) klass)->accept = (void (*) (ValadocContentContentElement*, ValadocContentContentVisitor*)) baladoc_content_list_real_accept;
	((ValadocContentContentElementClass *) klass)->accept_children = (void (*) (ValadocContentContentElement*, ValadocContentContentVisitor*)) baladoc_content_list_real_accept_children;
	((ValadocContentContentElementClass *) klass)->is_empty = (gboolean (*) (ValadocContentContentElement*)) baladoc_content_list_real_is_empty;
	((ValadocContentContentElementClass *) klass)->copy = (ValadocContentContentElement* (*) (ValadocContentContentElement*, ValadocContentContentElement*)) baladoc_content_list_real_copy;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_content_list_get_property;
	G_OBJECT_CLASS (klass)->set_property = _bala_baladoc_content_list_set_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_content_list_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_CONTENT_LIST_BULLET_PROPERTY, baladoc_content_list_properties[BALADOC_CONTENT_LIST_BULLET_PROPERTY] = g_param_spec_enum ("bullet", "bullet", "bullet", BALADOC_CONTENT_LIST_TYPE_BULLET, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_CONTENT_LIST_ITEMS_PROPERTY, baladoc_content_list_properties[BALADOC_CONTENT_LIST_ITEMS_PROPERTY] = bala_param_spec_iterable ("items", "items", "items", BALA_TYPE_LIST, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
baladoc_content_list_baladoc_content_block_interface_init (ValadocContentBlockIface * iface,
                                                           gpointer iface_data)
{
	baladoc_content_list_baladoc_content_block_parent_iface = g_type_interface_peek_parent (iface);
}

static void
baladoc_content_list_instance_init (ValadocContentList * self,
                                    gpointer klass)
{
	self->priv = baladoc_content_list_get_instance_private (self);
}

static void
baladoc_content_list_finalize (GObject * obj)
{
	ValadocContentList * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_CONTENT_TYPE_LIST, ValadocContentList);
	_bala_iterable_unref0 (self->priv->_items);
	G_OBJECT_CLASS (baladoc_content_list_parent_class)->finalize (obj);
}

static GType
baladoc_content_list_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocContentListClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_content_list_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocContentList), 0, (GInstanceInitFunc) baladoc_content_list_instance_init, NULL };
	static const GInterfaceInfo baladoc_content_block_info = { (GInterfaceInitFunc) baladoc_content_list_baladoc_content_block_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType baladoc_content_list_type_id;
	baladoc_content_list_type_id = g_type_register_static (BALADOC_CONTENT_TYPE_CONTENT_ELEMENT, "ValadocContentList", &g_define_type_info, 0);
	g_type_add_interface_static (baladoc_content_list_type_id, BALADOC_CONTENT_TYPE_BLOCK, &baladoc_content_block_info);
	ValadocContentList_private_offset = g_type_add_instance_private (baladoc_content_list_type_id, sizeof (ValadocContentListPrivate));
	return baladoc_content_list_type_id;
}

GType
baladoc_content_list_get_type (void)
{
	static volatile gsize baladoc_content_list_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_content_list_type_id__volatile)) {
		GType baladoc_content_list_type_id;
		baladoc_content_list_type_id = baladoc_content_list_get_type_once ();
		g_once_init_leave (&baladoc_content_list_type_id__volatile, baladoc_content_list_type_id);
	}
	return baladoc_content_list_type_id__volatile;
}

static void
_bala_baladoc_content_list_get_property (GObject * object,
                                         guint property_id,
                                         GValue * value,
                                         GParamSpec * pspec)
{
	ValadocContentList * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_CONTENT_TYPE_LIST, ValadocContentList);
	switch (property_id) {
		case BALADOC_CONTENT_LIST_BULLET_PROPERTY:
		g_value_set_enum (value, baladoc_content_list_get_bullet (self));
		break;
		case BALADOC_CONTENT_LIST_ITEMS_PROPERTY:
		bala_value_set_iterable (value, baladoc_content_list_get_items (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_bala_baladoc_content_list_set_property (GObject * object,
                                         guint property_id,
                                         const GValue * value,
                                         GParamSpec * pspec)
{
	ValadocContentList * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_CONTENT_TYPE_LIST, ValadocContentList);
	switch (property_id) {
		case BALADOC_CONTENT_LIST_BULLET_PROPERTY:
		baladoc_content_list_set_bullet (self, g_value_get_enum (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
