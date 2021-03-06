/* pointer.c generated by balac, the Bala compiler
 * generated from pointer.bala, do not modify */

/* pointer.bala
 *
 * Copyright (C) 2008  Florian Brosch
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
 * 	Florian Brosch <flo.brosch@gmail.com>
 */

#include "baladoc.h"
#include <glib.h>
#include <bala.h>

enum  {
	BALADOC_API_POINTER_0_PROPERTY,
	BALADOC_API_POINTER_DATA_TYPE_PROPERTY,
	BALADOC_API_POINTER_NUM_PROPERTIES
};
static GParamSpec* baladoc_api_pointer_properties[BALADOC_API_POINTER_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _baladoc_api_signature_builder_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_api_signature_builder_unref (var), NULL)))

struct _BaladocApiPointerPrivate {
	BaladocApiItem* _data_type;
};

static gint BaladocApiPointer_private_offset;
static gpointer baladoc_api_pointer_parent_class = NULL;

static BaladocContentInline* baladoc_api_pointer_real_build_signature (BaladocApiItem* base);
static void baladoc_api_pointer_finalize (GObject * obj);
static GType baladoc_api_pointer_get_type_once (void);
static void _bala_baladoc_api_pointer_get_property (GObject * object,
                                             guint property_id,
                                             GValue * value,
                                             GParamSpec * pspec);
static void _bala_baladoc_api_pointer_set_property (GObject * object,
                                             guint property_id,
                                             const GValue * value,
                                             GParamSpec * pspec);

static inline gpointer
baladoc_api_pointer_get_instance_private (BaladocApiPointer* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocApiPointer_private_offset);
}

BaladocApiItem*
baladoc_api_pointer_get_data_type (BaladocApiPointer* self)
{
	BaladocApiItem* result;
	BaladocApiItem* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data_type;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

void
baladoc_api_pointer_set_data_type (BaladocApiPointer* self,
                                   BaladocApiItem* value)
{
	BaladocApiItem* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_pointer_get_data_type (self);
	if (old_value != value) {
		BaladocApiItem* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_data_type);
		self->priv->_data_type = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_pointer_properties[BALADOC_API_POINTER_DATA_TYPE_PROPERTY]);
	}
}

BaladocApiPointer*
baladoc_api_pointer_construct (GType object_type,
                               BaladocApiItem* parent,
                               BalaPointerType* data)
{
	BaladocApiPointer * self = NULL;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (BaladocApiPointer*) baladoc_api_item_construct (object_type, (BalaCodeNode*) data);
	baladoc_api_item_set_parent ((BaladocApiItem*) self, parent);
	return self;
}

BaladocApiPointer*
baladoc_api_pointer_new (BaladocApiItem* parent,
                         BalaPointerType* data)
{
	return baladoc_api_pointer_construct (BALADOC_API_TYPE_POINTER, parent, data);
}

/**
 * {@inheritDoc}
 */
static BaladocContentInline*
baladoc_api_pointer_real_build_signature (BaladocApiItem* base)
{
	BaladocApiPointer * self;
	BaladocApiSignatureBuilder* _tmp0_;
	BaladocApiSignatureBuilder* _tmp1_;
	BaladocApiItem* _tmp2_;
	BaladocContentInline* _tmp3_;
	BaladocContentInline* _tmp4_;
	BaladocApiSignatureBuilder* _tmp5_;
	BaladocApiSignatureBuilder* _tmp6_;
	BaladocContentRun* _tmp7_;
	BaladocContentInline* _tmp8_;
	BaladocContentInline* result = NULL;
	self = (BaladocApiPointer*) base;
	_tmp0_ = baladoc_api_signature_builder_new ();
	_tmp1_ = _tmp0_;
	_tmp2_ = self->priv->_data_type;
	_tmp3_ = baladoc_api_item_get_signature (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = baladoc_api_signature_builder_append_content (_tmp1_, _tmp4_, TRUE);
	_tmp6_ = baladoc_api_signature_builder_append (_tmp5_, "*", FALSE);
	_tmp7_ = baladoc_api_signature_builder_get (_tmp6_);
	_tmp8_ = (BaladocContentInline*) _tmp7_;
	_baladoc_api_signature_builder_unref0 (_tmp1_);
	result = _tmp8_;
	return result;
}

static void
baladoc_api_pointer_class_init (BaladocApiPointerClass * klass,
                                gpointer klass_data)
{
	baladoc_api_pointer_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &BaladocApiPointer_private_offset);
	((BaladocApiItemClass *) klass)->build_signature = (BaladocContentInline* (*) (BaladocApiItem*)) baladoc_api_pointer_real_build_signature;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_api_pointer_get_property;
	G_OBJECT_CLASS (klass)->set_property = _bala_baladoc_api_pointer_set_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_api_pointer_finalize;
	/**
	 * The type the pointer is referring to.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_POINTER_DATA_TYPE_PROPERTY, baladoc_api_pointer_properties[BALADOC_API_POINTER_DATA_TYPE_PROPERTY] = g_param_spec_object ("data-type", "data-type", "data-type", BALADOC_API_TYPE_ITEM, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
}

static void
baladoc_api_pointer_instance_init (BaladocApiPointer * self,
                                   gpointer klass)
{
	self->priv = baladoc_api_pointer_get_instance_private (self);
}

static void
baladoc_api_pointer_finalize (GObject * obj)
{
	BaladocApiPointer * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_POINTER, BaladocApiPointer);
	_g_object_unref0 (self->priv->_data_type);
	G_OBJECT_CLASS (baladoc_api_pointer_parent_class)->finalize (obj);
}

/**
 * Represents a pointer declaration.
 */
static GType
baladoc_api_pointer_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocApiPointerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_pointer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocApiPointer), 0, (GInstanceInitFunc) baladoc_api_pointer_instance_init, NULL };
	GType baladoc_api_pointer_type_id;
	baladoc_api_pointer_type_id = g_type_register_static (BALADOC_API_TYPE_ITEM, "BaladocApiPointer", &g_define_type_info, 0);
	BaladocApiPointer_private_offset = g_type_add_instance_private (baladoc_api_pointer_type_id, sizeof (BaladocApiPointerPrivate));
	return baladoc_api_pointer_type_id;
}

GType
baladoc_api_pointer_get_type (void)
{
	static volatile gsize baladoc_api_pointer_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_pointer_type_id__volatile)) {
		GType baladoc_api_pointer_type_id;
		baladoc_api_pointer_type_id = baladoc_api_pointer_get_type_once ();
		g_once_init_leave (&baladoc_api_pointer_type_id__volatile, baladoc_api_pointer_type_id);
	}
	return baladoc_api_pointer_type_id__volatile;
}

static void
_bala_baladoc_api_pointer_get_property (GObject * object,
                                        guint property_id,
                                        GValue * value,
                                        GParamSpec * pspec)
{
	BaladocApiPointer * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_POINTER, BaladocApiPointer);
	switch (property_id) {
		case BALADOC_API_POINTER_DATA_TYPE_PROPERTY:
		g_value_set_object (value, baladoc_api_pointer_get_data_type (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_bala_baladoc_api_pointer_set_property (GObject * object,
                                        guint property_id,
                                        const GValue * value,
                                        GParamSpec * pspec)
{
	BaladocApiPointer * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_POINTER, BaladocApiPointer);
	switch (property_id) {
		case BALADOC_API_POINTER_DATA_TYPE_PROPERTY:
		baladoc_api_pointer_set_data_type (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

