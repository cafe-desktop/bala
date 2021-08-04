/* symbol.c generated by balac, the Vala compiler
 * generated from symbol.bala, do not modify */

/* symbol.bala
 *
 * Copyright (C) 2008-2009 Florian Brosch, Didier Villevalois
 * Copyright (C) 2011      Florian Brosch
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
#include <glib.h>
#include <bala.h>
#include <stdlib.h>
#include <string.h>

enum  {
	BALADOC_API_SYMBOL_0_PROPERTY,
	BALADOC_API_SYMBOL_IS_DEPRECATED_PROPERTY,
	BALADOC_API_SYMBOL_ACCESSIBILITY_PROPERTY,
	BALADOC_API_SYMBOL_IS_PUBLIC_PROPERTY,
	BALADOC_API_SYMBOL_IS_PROTECTED_PROPERTY,
	BALADOC_API_SYMBOL_IS_INTERNAL_PROPERTY,
	BALADOC_API_SYMBOL_IS_PRIVATE_PROPERTY,
	BALADOC_API_SYMBOL_NUM_PROPERTIES
};
static GParamSpec* baladoc_api_symbol_properties[BALADOC_API_SYMBOL_NUM_PROPERTIES];
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _baladoc_api_source_comment_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_api_source_comment_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _ValadocApiSymbolPrivate {
	ValaArrayList* attributes;
	ValadocApiSourceComment* source_comment;
	gboolean _is_deprecated;
	ValaSymbolAccessibility _accessibility;
};

static gint ValadocApiSymbol_private_offset;
static gpointer baladoc_api_symbol_parent_class = NULL;

G_GNUC_INTERNAL void baladoc_api_item_parse_comments (ValadocApiItem* self,
                                      ValadocSettings* settings,
                                      ValadocDocumentationParser* parser);
G_GNUC_INTERNAL void baladoc_api_item_check_comments (ValadocApiItem* self,
                                      ValadocSettings* settings,
                                      ValadocDocumentationParser* parser);
static void baladoc_api_symbol_set_is_deprecated (ValadocApiSymbol* self,
                                           gboolean value);
static void baladoc_api_symbol_set_accessibility (ValadocApiSymbol* self,
                                           ValaSymbolAccessibility value);
G_GNUC_INTERNAL void baladoc_api_package_register_deprecated_symbol (ValadocApiPackage* self,
                                                     ValadocApiSymbol* symbol,
                                                     const gchar* version);
static gboolean baladoc_api_symbol_real_is_browsable (ValadocApiNode* base,
                                               ValadocSettings* settings);
static void baladoc_api_symbol_real_parse_comments (ValadocApiItem* base,
                                             ValadocSettings* settings,
                                             ValadocDocumentationParser* parser);
G_GNUC_INTERNAL void baladoc_api_node_set_documentation (ValadocApiNode* self,
                                         ValadocContentComment* value);
static void baladoc_api_symbol_real_check_comments (ValadocApiItem* base,
                                             ValadocSettings* settings,
                                             ValadocDocumentationParser* parser);
static void baladoc_api_symbol_finalize (GObject * obj);
static GType baladoc_api_symbol_get_type_once (void);
static void _bala_baladoc_api_symbol_get_property (GObject * object,
                                            guint property_id,
                                            GValue * value,
                                            GParamSpec * pspec);
static void _bala_baladoc_api_symbol_set_property (GObject * object,
                                            guint property_id,
                                            const GValue * value,
                                            GParamSpec * pspec);

static inline gpointer
baladoc_api_symbol_get_instance_private (ValadocApiSymbol* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocApiSymbol_private_offset);
}

gboolean
baladoc_api_symbol_get_is_deprecated (ValadocApiSymbol* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_deprecated;
	return result;
}

static void
baladoc_api_symbol_set_is_deprecated (ValadocApiSymbol* self,
                                      gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_symbol_get_is_deprecated (self);
	if (old_value != value) {
		self->priv->_is_deprecated = value;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_IS_DEPRECATED_PROPERTY]);
	}
}

static gpointer
_baladoc_api_source_comment_ref0 (gpointer self)
{
	return self ? baladoc_api_source_comment_ref (self) : NULL;
}

ValadocApiSymbol*
baladoc_api_symbol_construct (GType object_type,
                              ValadocApiNode* parent,
                              ValadocApiSourceFile* file,
                              const gchar* name,
                              ValaSymbolAccessibility accessibility,
                              ValadocApiSourceComment* comment,
                              ValaSymbol* data)
{
	ValadocApiSymbol * self = NULL;
	ValadocApiSourceComment* _tmp0_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (ValadocApiSymbol*) baladoc_api_node_construct (object_type, parent, file, name, (ValaCodeNode*) data);
	baladoc_api_symbol_set_accessibility (self, accessibility);
	_tmp0_ = _baladoc_api_source_comment_ref0 (comment);
	_baladoc_api_source_comment_unref0 (self->priv->source_comment);
	self->priv->source_comment = _tmp0_;
	return self;
}

static gpointer
_bala_code_node_ref0 (gpointer self)
{
	return self ? bala_code_node_ref (self) : NULL;
}

void
baladoc_api_symbol_add_attribute (ValadocApiSymbol* self,
                                  ValadocApiAttribute* att)
{
	ValaArrayList* _tmp0_;
	ValaAttribute* attr = NULL;
	ValaCodeNode* _tmp3_;
	ValaCodeNode* _tmp4_;
	ValaAttribute* _tmp5_;
	const gchar* _tmp6_;
	const gchar* _tmp7_;
	ValaArrayList* _tmp23_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (att != NULL);
	_tmp0_ = self->priv->attributes;
	if (_tmp0_ == NULL) {
		GEqualFunc _tmp1_;
		ValaArrayList* _tmp2_;
		_tmp1_ = g_direct_equal;
		_tmp2_ = bala_array_list_new (BALADOC_API_TYPE_ATTRIBUTE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp1_);
		_bala_iterable_unref0 (self->priv->attributes);
		self->priv->attributes = _tmp2_;
	}
	_tmp3_ = baladoc_api_item_get_data ((ValadocApiItem*) att);
	_tmp4_ = _tmp3_;
	_tmp5_ = _bala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp4_, BALA_TYPE_ATTRIBUTE, ValaAttribute));
	attr = _tmp5_;
	_tmp6_ = baladoc_api_attribute_get_name (att);
	_tmp7_ = _tmp6_;
	if (g_strcmp0 (_tmp7_, "Version") == 0) {
		gboolean deprecated = FALSE;
		ValaAttribute* _tmp8_;
		gchar* version = NULL;
		ValaAttribute* _tmp9_;
		gchar* _tmp10_;
		gboolean _tmp11_ = FALSE;
		_tmp8_ = attr;
		deprecated = bala_attribute_get_bool (_tmp8_, "deprecated", FALSE);
		_tmp9_ = attr;
		_tmp10_ = bala_attribute_get_string (_tmp9_, "deprecated_since", NULL);
		version = _tmp10_;
		if (deprecated) {
			_tmp11_ = TRUE;
		} else {
			const gchar* _tmp12_;
			_tmp12_ = version;
			_tmp11_ = _tmp12_ != NULL;
		}
		if (_tmp11_) {
			ValadocApiPackage* _tmp13_;
			ValadocApiPackage* _tmp14_;
			const gchar* _tmp15_;
			_tmp13_ = baladoc_documentation_get_package ((ValadocDocumentation*) self);
			_tmp14_ = _tmp13_;
			_tmp15_ = version;
			baladoc_api_package_register_deprecated_symbol (_tmp14_, self, _tmp15_);
			baladoc_api_symbol_set_is_deprecated (self, TRUE);
		}
		_g_free0 (version);
	} else {
		const gchar* _tmp16_;
		const gchar* _tmp17_;
		_tmp16_ = baladoc_api_attribute_get_name (att);
		_tmp17_ = _tmp16_;
		if (g_strcmp0 (_tmp17_, "Deprecated") == 0) {
			gchar* version = NULL;
			ValaAttribute* _tmp18_;
			gchar* _tmp19_;
			ValadocApiPackage* _tmp20_;
			ValadocApiPackage* _tmp21_;
			const gchar* _tmp22_;
			_tmp18_ = attr;
			_tmp19_ = bala_attribute_get_string (_tmp18_, "version", NULL);
			version = _tmp19_;
			_tmp20_ = baladoc_documentation_get_package ((ValadocDocumentation*) self);
			_tmp21_ = _tmp20_;
			_tmp22_ = version;
			baladoc_api_package_register_deprecated_symbol (_tmp21_, self, _tmp22_);
			baladoc_api_symbol_set_is_deprecated (self, TRUE);
			_g_free0 (version);
		}
	}
	_tmp23_ = self->priv->attributes;
	bala_collection_add ((ValaCollection*) _tmp23_, att);
	_bala_code_node_unref0 (attr);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

ValaCollection*
baladoc_api_symbol_get_attributes (ValadocApiSymbol* self)
{
	ValaArrayList* _tmp0_;
	ValaCollection* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->attributes;
	if (_tmp0_ == NULL) {
		GEqualFunc _tmp1_;
		ValaArrayList* _tmp2_;
		_tmp1_ = g_direct_equal;
		_tmp2_ = bala_array_list_new (BALADOC_API_TYPE_ATTRIBUTE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp1_);
		result = (ValaCollection*) _tmp2_;
		return result;
	} else {
		ValaArrayList* _tmp3_;
		ValaCollection* _tmp4_;
		_tmp3_ = self->priv->attributes;
		_tmp4_ = _bala_iterable_ref0 ((ValaCollection*) _tmp3_);
		result = _tmp4_;
		return result;
	}
}

ValadocApiAttribute*
baladoc_api_symbol_get_attribute (ValadocApiSymbol* self,
                                  const gchar* name)
{
	ValaArrayList* _tmp0_;
	ValadocApiAttribute* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = self->priv->attributes;
	if (_tmp0_ != NULL) {
		{
			ValaArrayList* _att_list = NULL;
			ValaArrayList* _tmp1_;
			ValaArrayList* _tmp2_;
			gint _att_size = 0;
			ValaArrayList* _tmp3_;
			gint _tmp4_;
			gint _tmp5_;
			gint _att_index = 0;
			_tmp1_ = self->priv->attributes;
			_tmp2_ = _bala_iterable_ref0 (_tmp1_);
			_att_list = _tmp2_;
			_tmp3_ = _att_list;
			_tmp4_ = bala_collection_get_size ((ValaCollection*) _tmp3_);
			_tmp5_ = _tmp4_;
			_att_size = _tmp5_;
			_att_index = -1;
			while (TRUE) {
				gint _tmp6_;
				gint _tmp7_;
				ValadocApiAttribute* att = NULL;
				ValaArrayList* _tmp8_;
				gpointer _tmp9_;
				ValadocApiAttribute* _tmp10_;
				const gchar* _tmp11_;
				const gchar* _tmp12_;
				_att_index = _att_index + 1;
				_tmp6_ = _att_index;
				_tmp7_ = _att_size;
				if (!(_tmp6_ < _tmp7_)) {
					break;
				}
				_tmp8_ = _att_list;
				_tmp9_ = bala_list_get ((ValaList*) _tmp8_, _att_index);
				att = (ValadocApiAttribute*) _tmp9_;
				_tmp10_ = att;
				_tmp11_ = baladoc_api_attribute_get_name (_tmp10_);
				_tmp12_ = _tmp11_;
				if (g_strcmp0 (_tmp12_, name) == 0) {
					result = att;
					_bala_iterable_unref0 (_att_list);
					return result;
				}
				_g_object_unref0 (att);
			}
			_bala_iterable_unref0 (_att_list);
		}
	}
	result = NULL;
	return result;
}

/**
 * {@inheritDoc}
 */
static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static gboolean
baladoc_api_symbol_real_is_browsable (ValadocApiNode* base,
                                      ValadocSettings* settings)
{
	ValadocApiSymbol * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp6_ = FALSE;
	ValadocApiItem* pos = NULL;
	ValadocApiItem* _tmp9_;
	ValadocApiItem* _tmp10_;
	ValadocApiItem* _tmp11_;
	gboolean result = FALSE;
	self = (ValadocApiSymbol*) base;
	g_return_val_if_fail (settings != NULL, FALSE);
	if (!settings->_private) {
		gboolean _tmp1_;
		gboolean _tmp2_;
		_tmp1_ = baladoc_api_symbol_get_is_private (self);
		_tmp2_ = _tmp1_;
		_tmp0_ = _tmp2_;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		result = FALSE;
		return result;
	}
	if (!settings->_internal) {
		gboolean _tmp4_;
		gboolean _tmp5_;
		_tmp4_ = baladoc_api_symbol_get_is_internal (self);
		_tmp5_ = _tmp4_;
		_tmp3_ = _tmp5_;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		result = FALSE;
		return result;
	}
	if (!settings->_protected) {
		gboolean _tmp7_;
		gboolean _tmp8_;
		_tmp7_ = baladoc_api_symbol_get_is_protected (self);
		_tmp8_ = _tmp7_;
		_tmp6_ = _tmp8_;
	} else {
		_tmp6_ = FALSE;
	}
	if (_tmp6_) {
		result = FALSE;
		return result;
	}
	_tmp9_ = baladoc_api_item_get_parent ((ValadocApiItem*) self);
	_tmp10_ = _tmp9_;
	_tmp11_ = _g_object_ref0 (_tmp10_);
	pos = _tmp11_;
	while (TRUE) {
		gboolean _tmp12_ = FALSE;
		gboolean _tmp13_ = FALSE;
		ValadocApiItem* _tmp14_;
		ValadocApiItem* _tmp17_;
		ValadocApiItem* _tmp18_;
		ValadocApiItem* _tmp19_;
		ValadocApiItem* _tmp20_;
		ValadocApiItem* _tmp21_;
		_tmp14_ = pos;
		if (_tmp14_ != NULL) {
			ValadocApiItem* _tmp15_;
			_tmp15_ = pos;
			_tmp13_ = BALADOC_API_IS_SYMBOL (_tmp15_);
		} else {
			_tmp13_ = FALSE;
		}
		if (_tmp13_) {
			ValadocApiItem* _tmp16_;
			_tmp16_ = pos;
			_tmp12_ = BALADOC_API_IS_NAMESPACE (_tmp16_) == FALSE;
		} else {
			_tmp12_ = FALSE;
		}
		if (!_tmp12_) {
			break;
		}
		_tmp17_ = pos;
		if (baladoc_api_node_is_browsable ((ValadocApiNode*) G_TYPE_CHECK_INSTANCE_CAST (_tmp17_, BALADOC_API_TYPE_SYMBOL, ValadocApiSymbol), settings) == FALSE) {
			result = FALSE;
			_g_object_unref0 (pos);
			return result;
		}
		_tmp18_ = pos;
		_tmp19_ = baladoc_api_item_get_parent (_tmp18_);
		_tmp20_ = _tmp19_;
		_tmp21_ = _g_object_ref0 (_tmp20_);
		_g_object_unref0 (pos);
		pos = _tmp21_;
	}
	result = TRUE;
	_g_object_unref0 (pos);
	return result;
}

ValaSymbolAccessibility
baladoc_api_symbol_get_accessibility (ValadocApiSymbol* self)
{
	ValaSymbolAccessibility result;
	ValaSymbolAccessibility _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_accessibility;
	result = _tmp0_;
	return result;
}

static void
baladoc_api_symbol_set_accessibility (ValadocApiSymbol* self,
                                      ValaSymbolAccessibility value)
{
	ValaSymbolAccessibility old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_symbol_get_accessibility (self);
	if (old_value != value) {
		self->priv->_accessibility = value;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_ACCESSIBILITY_PROPERTY]);
	}
}

gboolean
baladoc_api_symbol_get_is_public (ValadocApiSymbol* self)
{
	gboolean result;
	ValaSymbolAccessibility _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_accessibility;
	result = _tmp0_ == BALA_SYMBOL_ACCESSIBILITY_PUBLIC;
	return result;
}

gboolean
baladoc_api_symbol_get_is_protected (ValadocApiSymbol* self)
{
	gboolean result;
	ValaSymbolAccessibility _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_accessibility;
	result = _tmp0_ == BALA_SYMBOL_ACCESSIBILITY_PROTECTED;
	return result;
}

gboolean
baladoc_api_symbol_get_is_internal (ValadocApiSymbol* self)
{
	gboolean result;
	ValaSymbolAccessibility _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_accessibility;
	result = _tmp0_ == BALA_SYMBOL_ACCESSIBILITY_INTERNAL;
	return result;
}

gboolean
baladoc_api_symbol_get_is_private (ValadocApiSymbol* self)
{
	gboolean result;
	ValaSymbolAccessibility _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_accessibility;
	result = _tmp0_ == BALA_SYMBOL_ACCESSIBILITY_PRIVATE;
	return result;
}

/**
 * {@inheritDoc}
 */
static void
baladoc_api_symbol_real_parse_comments (ValadocApiItem* base,
                                        ValadocSettings* settings,
                                        ValadocDocumentationParser* parser)
{
	ValadocApiSymbol * self;
	ValadocContentComment* _tmp0_;
	ValadocContentComment* _tmp1_;
	ValadocApiSourceComment* _tmp2_;
	self = (ValadocApiSymbol*) base;
	g_return_if_fail (settings != NULL);
	g_return_if_fail (parser != NULL);
	_tmp0_ = baladoc_api_node_get_documentation ((ValadocApiNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		return;
	}
	_tmp2_ = self->priv->source_comment;
	if (_tmp2_ != NULL) {
		ValadocApiSourceComment* _tmp3_;
		ValadocContentComment* _tmp4_;
		ValadocContentComment* _tmp5_;
		_tmp3_ = self->priv->source_comment;
		_tmp4_ = baladoc_documentation_parser_parse (parser, (ValadocApiNode*) self, _tmp3_);
		_tmp5_ = _tmp4_;
		baladoc_api_node_set_documentation ((ValadocApiNode*) self, _tmp5_);
		_g_object_unref0 (_tmp5_);
	}
	BALADOC_API_ITEM_CLASS (baladoc_api_symbol_parent_class)->parse_comments ((ValadocApiItem*) G_TYPE_CHECK_INSTANCE_CAST (self, BALADOC_API_TYPE_NODE, ValadocApiNode), settings, parser);
}

/**
 * {@inheritDoc}
 */
static void
baladoc_api_symbol_real_check_comments (ValadocApiItem* base,
                                        ValadocSettings* settings,
                                        ValadocDocumentationParser* parser)
{
	ValadocApiSymbol * self;
	ValadocContentComment* _tmp0_;
	ValadocContentComment* _tmp1_;
	self = (ValadocApiSymbol*) base;
	g_return_if_fail (settings != NULL);
	g_return_if_fail (parser != NULL);
	_tmp0_ = baladoc_api_node_get_documentation ((ValadocApiNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValadocContentComment* _tmp2_;
		ValadocContentComment* _tmp3_;
		_tmp2_ = baladoc_api_node_get_documentation ((ValadocApiNode*) self);
		_tmp3_ = _tmp2_;
		baladoc_documentation_parser_check (parser, (ValadocApiNode*) self, _tmp3_);
	}
	BALADOC_API_ITEM_CLASS (baladoc_api_symbol_parent_class)->check_comments ((ValadocApiItem*) G_TYPE_CHECK_INSTANCE_CAST (self, BALADOC_API_TYPE_NODE, ValadocApiNode), settings, parser);
}

static void
baladoc_api_symbol_class_init (ValadocApiSymbolClass * klass,
                               gpointer klass_data)
{
	baladoc_api_symbol_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocApiSymbol_private_offset);
	((ValadocApiNodeClass *) klass)->is_browsable = (gboolean (*) (ValadocApiNode*, ValadocSettings*)) baladoc_api_symbol_real_is_browsable;
	((ValadocApiItemClass *) klass)->parse_comments = (void (*) (ValadocApiItem*, ValadocSettings*, ValadocDocumentationParser*)) baladoc_api_symbol_real_parse_comments;
	((ValadocApiItemClass *) klass)->check_comments = (void (*) (ValadocApiItem*, ValadocSettings*, ValadocDocumentationParser*)) baladoc_api_symbol_real_check_comments;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_api_symbol_get_property;
	G_OBJECT_CLASS (klass)->set_property = _bala_baladoc_api_symbol_set_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_api_symbol_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SYMBOL_IS_DEPRECATED_PROPERTY, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_IS_DEPRECATED_PROPERTY] = g_param_spec_boolean ("is-deprecated", "is-deprecated", "is-deprecated", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SYMBOL_ACCESSIBILITY_PROPERTY, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_ACCESSIBILITY_PROPERTY] = g_param_spec_enum ("accessibility", "accessibility", "accessibility", BALA_TYPE_SYMBOL_ACCESSIBILITY, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this symbol is public.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SYMBOL_IS_PUBLIC_PROPERTY, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_IS_PUBLIC_PROPERTY] = g_param_spec_boolean ("is-public", "is-public", "is-public", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this symbol is protected.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SYMBOL_IS_PROTECTED_PROPERTY, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_IS_PROTECTED_PROPERTY] = g_param_spec_boolean ("is-protected", "is-protected", "is-protected", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this symbol is internal.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SYMBOL_IS_INTERNAL_PROPERTY, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_IS_INTERNAL_PROPERTY] = g_param_spec_boolean ("is-internal", "is-internal", "is-internal", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	/**
	 * Specifies whether this symbol is private.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SYMBOL_IS_PRIVATE_PROPERTY, baladoc_api_symbol_properties[BALADOC_API_SYMBOL_IS_PRIVATE_PROPERTY] = g_param_spec_boolean ("is-private", "is-private", "is-private", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
baladoc_api_symbol_instance_init (ValadocApiSymbol * self,
                                  gpointer klass)
{
	self->priv = baladoc_api_symbol_get_instance_private (self);
	self->priv->_is_deprecated = FALSE;
}

static void
baladoc_api_symbol_finalize (GObject * obj)
{
	ValadocApiSymbol * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_SYMBOL, ValadocApiSymbol);
	_bala_iterable_unref0 (self->priv->attributes);
	_baladoc_api_source_comment_unref0 (self->priv->source_comment);
	G_OBJECT_CLASS (baladoc_api_symbol_parent_class)->finalize (obj);
}

/**
 * Represents a node in the symbol tree.
 */
static GType
baladoc_api_symbol_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocApiSymbolClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_symbol_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocApiSymbol), 0, (GInstanceInitFunc) baladoc_api_symbol_instance_init, NULL };
	GType baladoc_api_symbol_type_id;
	baladoc_api_symbol_type_id = g_type_register_static (BALADOC_API_TYPE_NODE, "ValadocApiSymbol", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	ValadocApiSymbol_private_offset = g_type_add_instance_private (baladoc_api_symbol_type_id, sizeof (ValadocApiSymbolPrivate));
	return baladoc_api_symbol_type_id;
}

GType
baladoc_api_symbol_get_type (void)
{
	static volatile gsize baladoc_api_symbol_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_symbol_type_id__volatile)) {
		GType baladoc_api_symbol_type_id;
		baladoc_api_symbol_type_id = baladoc_api_symbol_get_type_once ();
		g_once_init_leave (&baladoc_api_symbol_type_id__volatile, baladoc_api_symbol_type_id);
	}
	return baladoc_api_symbol_type_id__volatile;
}

static void
_bala_baladoc_api_symbol_get_property (GObject * object,
                                       guint property_id,
                                       GValue * value,
                                       GParamSpec * pspec)
{
	ValadocApiSymbol * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_SYMBOL, ValadocApiSymbol);
	switch (property_id) {
		case BALADOC_API_SYMBOL_IS_DEPRECATED_PROPERTY:
		g_value_set_boolean (value, baladoc_api_symbol_get_is_deprecated (self));
		break;
		case BALADOC_API_SYMBOL_ACCESSIBILITY_PROPERTY:
		g_value_set_enum (value, baladoc_api_symbol_get_accessibility (self));
		break;
		case BALADOC_API_SYMBOL_IS_PUBLIC_PROPERTY:
		g_value_set_boolean (value, baladoc_api_symbol_get_is_public (self));
		break;
		case BALADOC_API_SYMBOL_IS_PROTECTED_PROPERTY:
		g_value_set_boolean (value, baladoc_api_symbol_get_is_protected (self));
		break;
		case BALADOC_API_SYMBOL_IS_INTERNAL_PROPERTY:
		g_value_set_boolean (value, baladoc_api_symbol_get_is_internal (self));
		break;
		case BALADOC_API_SYMBOL_IS_PRIVATE_PROPERTY:
		g_value_set_boolean (value, baladoc_api_symbol_get_is_private (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_bala_baladoc_api_symbol_set_property (GObject * object,
                                       guint property_id,
                                       const GValue * value,
                                       GParamSpec * pspec)
{
	ValadocApiSymbol * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_SYMBOL, ValadocApiSymbol);
	switch (property_id) {
		case BALADOC_API_SYMBOL_IS_DEPRECATED_PROPERTY:
		baladoc_api_symbol_set_is_deprecated (self, g_value_get_boolean (value));
		break;
		case BALADOC_API_SYMBOL_ACCESSIBILITY_PROPERTY:
		baladoc_api_symbol_set_accessibility (self, g_value_get_enum (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
