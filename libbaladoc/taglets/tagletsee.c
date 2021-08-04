/* tagletsee.c generated by valac, the Vala compiler
 * generated from tagletsee.vala, do not modify */

/* tagletsee.vala
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
#include <glib-object.h>

enum  {
	BALADOC_TAGLETS_SEE_0_PROPERTY,
	BALADOC_TAGLETS_SEE_SYMBOL_NAME_PROPERTY,
	BALADOC_TAGLETS_SEE_SYMBOL_PROPERTY,
	BALADOC_TAGLETS_SEE_NUM_PROPERTIES
};
static GParamSpec* valadoc_taglets_see_properties[BALADOC_TAGLETS_SEE_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _ValadocTagletsSeePrivate {
	gchar* _symbol_name;
	ValadocApiNode* _symbol;
};

static gint ValadocTagletsSee_private_offset;
static gpointer valadoc_taglets_see_parent_class = NULL;
static ValadocContentTagletIface * valadoc_taglets_see_valadoc_content_taglet_parent_iface = NULL;
static ValadocContentBlockIface * valadoc_taglets_see_valadoc_content_block_parent_iface = NULL;

static void valadoc_taglets_see_set_symbol_name (ValadocTagletsSee* self,
                                          const gchar* value);
static void valadoc_taglets_see_set_symbol (ValadocTagletsSee* self,
                                     ValadocApiNode* value);
static ValadocRule* valadoc_taglets_see_real_get_parser_rule (ValadocContentTaglet* base,
                                                       ValadocRule* run_rule);
static void __lambda128_ (ValadocTagletsSee* self,
                   ValadocToken* token,
                   GError** error);
static void ___lambda128__valadoc_token_type_action (ValadocToken* token,
                                              gpointer self,
                                              GError** error);
static void valadoc_taglets_see_real_check (ValadocContentContentElement* base,
                                     ValadocApiTree* api_root,
                                     ValadocApiNode* container,
                                     const gchar* file_path,
                                     ValadocErrorReporter* reporter,
                                     ValadocSettings* settings);
static void valadoc_taglets_see_real_accept (ValadocContentContentElement* base,
                                      ValadocContentContentVisitor* visitor);
static gboolean valadoc_taglets_see_real_is_empty (ValadocContentContentElement* base);
static ValadocContentContentElement* valadoc_taglets_see_real_copy (ValadocContentContentElement* base,
                                                             ValadocContentContentElement* new_parent);
G_GNUC_INTERNAL void valadoc_content_content_element_set_parent (ValadocContentContentElement* self,
                                                 ValadocContentContentElement* value);
static void valadoc_taglets_see_finalize (GObject * obj);
static GType valadoc_taglets_see_get_type_once (void);
static void _vala_valadoc_taglets_see_get_property (GObject * object,
                                             guint property_id,
                                             GValue * value,
                                             GParamSpec * pspec);
static void _vala_valadoc_taglets_see_set_property (GObject * object,
                                             guint property_id,
                                             const GValue * value,
                                             GParamSpec * pspec);
static void _vala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);

static inline gpointer
valadoc_taglets_see_get_instance_private (ValadocTagletsSee* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocTagletsSee_private_offset);
}

const gchar*
valadoc_taglets_see_get_symbol_name (ValadocTagletsSee* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_symbol_name;
	result = _tmp0_;
	return result;
}

static void
valadoc_taglets_see_set_symbol_name (ValadocTagletsSee* self,
                                     const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_taglets_see_get_symbol_name (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_symbol_name);
		self->priv->_symbol_name = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_taglets_see_properties[BALADOC_TAGLETS_SEE_SYMBOL_NAME_PROPERTY]);
	}
}

ValadocApiNode*
valadoc_taglets_see_get_symbol (ValadocTagletsSee* self)
{
	ValadocApiNode* result;
	ValadocApiNode* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_symbol;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
valadoc_taglets_see_set_symbol (ValadocTagletsSee* self,
                                ValadocApiNode* value)
{
	ValadocApiNode* old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_taglets_see_get_symbol (self);
	if (old_value != value) {
		ValadocApiNode* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_symbol);
		self->priv->_symbol = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, valadoc_taglets_see_properties[BALADOC_TAGLETS_SEE_SYMBOL_PROPERTY]);
	}
}

static void
__lambda128_ (ValadocTagletsSee* self,
              ValadocToken* token,
              GError** error)
{
	const gchar* _tmp0_;
	g_return_if_fail (token != NULL);
	_tmp0_ = valadoc_token_to_string (token);
	valadoc_taglets_see_set_symbol_name (self, _tmp0_);
}

static void
___lambda128__valadoc_token_type_action (ValadocToken* token,
                                         gpointer self,
                                         GError** error)
{
	__lambda128_ ((ValadocTagletsSee*) self, token, error);
}

static ValadocRule*
valadoc_taglets_see_real_get_parser_rule (ValadocContentTaglet* base,
                                          ValadocRule* run_rule)
{
	ValadocTagletsSee * self;
	ValadocRule* optional_spaces = NULL;
	ValadocTokenType* _tmp0_;
	GObject* _tmp1_;
	GObject** _tmp2_;
	GObject** _tmp3_;
	gint _tmp3__length1;
	ValadocRule* _tmp4_;
	GObject** _tmp5_;
	GObject** _tmp6_;
	gint _tmp6__length1;
	ValadocRule* _tmp7_;
	ValadocRule* _tmp8_;
	GObject* _tmp9_;
	ValadocTokenType* _tmp10_;
	ValadocTokenType* _tmp11_;
	ValadocTokenType* _tmp12_;
	GObject* _tmp13_;
	GObject** _tmp14_;
	GObject** _tmp15_;
	gint _tmp15__length1;
	ValadocRule* _tmp16_;
	ValadocRule* _tmp17_;
	ValadocRule* result = NULL;
	self = (ValadocTagletsSee*) base;
	g_return_val_if_fail (run_rule != NULL, NULL);
	_tmp0_ = valadoc_token_type_SPACE;
	_tmp1_ = _g_object_ref0 ((GObject*) _tmp0_);
	_tmp2_ = g_new0 (GObject*, 1 + 1);
	_tmp2_[0] = _tmp1_;
	_tmp3_ = _tmp2_;
	_tmp3__length1 = 1;
	_tmp4_ = valadoc_rule_many (_tmp3_, (gint) 1);
	_tmp5_ = g_new0 (GObject*, 1 + 1);
	_tmp5_[0] = (GObject*) _tmp4_;
	_tmp6_ = _tmp5_;
	_tmp6__length1 = 1;
	_tmp7_ = valadoc_rule_option (_tmp6_, (gint) 1);
	_tmp8_ = _tmp7_;
	_tmp6_ = (_vala_array_free (_tmp6_, _tmp6__length1, (GDestroyNotify) g_object_unref), NULL);
	_tmp3_ = (_vala_array_free (_tmp3_, _tmp3__length1, (GDestroyNotify) g_object_unref), NULL);
	optional_spaces = _tmp8_;
	_tmp9_ = _g_object_ref0 ((GObject*) optional_spaces);
	_tmp10_ = valadoc_token_type_any_word ();
	_tmp11_ = _tmp10_;
	_tmp12_ = valadoc_token_type_action (_tmp11_, ___lambda128__valadoc_token_type_action, self);
	_tmp13_ = _g_object_ref0 ((GObject*) optional_spaces);
	_tmp14_ = g_new0 (GObject*, 3 + 1);
	_tmp14_[0] = _tmp9_;
	_tmp14_[1] = (GObject*) _tmp12_;
	_tmp14_[2] = _tmp13_;
	_tmp15_ = _tmp14_;
	_tmp15__length1 = 3;
	_tmp16_ = valadoc_rule_seq (_tmp15_, (gint) 3);
	_tmp17_ = _tmp16_;
	_tmp15_ = (_vala_array_free (_tmp15_, _tmp15__length1, (GDestroyNotify) g_object_unref), NULL);
	_g_object_unref0 (_tmp11_);
	result = _tmp17_;
	_g_object_unref0 (optional_spaces);
	return result;
}

static glong
string_strnlen (gchar* str,
                glong maxlen)
{
	gchar* end = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	glong result = 0L;
	_tmp0_ = memchr (str, 0, (gsize) maxlen);
	end = _tmp0_;
	_tmp1_ = end;
	if (_tmp1_ == NULL) {
		result = maxlen;
		return result;
	} else {
		gchar* _tmp2_;
		_tmp2_ = end;
		result = (glong) (_tmp2_ - str);
		return result;
	}
}

static gchar*
string_substring (const gchar* self,
                  glong offset,
                  glong len)
{
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	gchar* _tmp3_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	if (offset >= ((glong) 0)) {
		_tmp0_ = len >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		string_length = string_strnlen ((gchar*) self, offset + len);
	} else {
		gint _tmp1_;
		gint _tmp2_;
		_tmp1_ = strlen (self);
		_tmp2_ = _tmp1_;
		string_length = (glong) _tmp2_;
	}
	if (offset < ((glong) 0)) {
		offset = string_length + offset;
		g_return_val_if_fail (offset >= ((glong) 0), NULL);
	} else {
		g_return_val_if_fail (offset <= string_length, NULL);
	}
	if (len < ((glong) 0)) {
		len = string_length - offset;
	}
	g_return_val_if_fail ((offset + len) <= string_length, NULL);
	_tmp3_ = g_strndup (((gchar*) self) + offset, (gsize) len);
	result = _tmp3_;
	return result;
}

static void
valadoc_taglets_see_real_check (ValadocContentContentElement* base,
                                ValadocApiTree* api_root,
                                ValadocApiNode* container,
                                const gchar* file_path,
                                ValadocErrorReporter* reporter,
                                ValadocSettings* settings)
{
	ValadocTagletsSee * self;
	const gchar* _tmp0_;
	ValadocApiNode* _tmp14_;
	self = (ValadocTagletsSee*) base;
	g_return_if_fail (api_root != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (file_path != NULL);
	g_return_if_fail (reporter != NULL);
	g_return_if_fail (settings != NULL);
	_tmp0_ = self->priv->_symbol_name;
	if (g_str_has_prefix (_tmp0_, "c::")) {
		const gchar* _tmp1_;
		gchar* _tmp2_;
		gchar* _tmp3_;
		const gchar* _tmp4_;
		ValadocApiNode* _tmp5_;
		ValadocApiNode* _tmp6_;
		ValadocApiNode* _tmp7_;
		_tmp1_ = self->priv->_symbol_name;
		_tmp2_ = string_substring (_tmp1_, (glong) 3, (glong) -1);
		_tmp3_ = _tmp2_;
		valadoc_taglets_see_set_symbol_name (self, _tmp3_);
		_g_free0 (_tmp3_);
		_tmp4_ = self->priv->_symbol_name;
		_tmp5_ = valadoc_api_tree_search_symbol_cstr (api_root, container, _tmp4_);
		_tmp6_ = _tmp5_;
		valadoc_taglets_see_set_symbol (self, _tmp6_);
		_g_object_unref0 (_tmp6_);
		_tmp7_ = self->priv->_symbol;
		if (_tmp7_ != NULL) {
			ValadocApiNode* _tmp8_;
			const gchar* _tmp9_;
			const gchar* _tmp10_;
			_tmp8_ = self->priv->_symbol;
			_tmp9_ = valadoc_api_node_get_name (_tmp8_);
			_tmp10_ = _tmp9_;
			valadoc_taglets_see_set_symbol_name (self, _tmp10_);
		}
	} else {
		const gchar* _tmp11_;
		ValadocApiNode* _tmp12_;
		ValadocApiNode* _tmp13_;
		_tmp11_ = self->priv->_symbol_name;
		_tmp12_ = valadoc_api_tree_search_symbol_str (api_root, container, _tmp11_);
		_tmp13_ = _tmp12_;
		valadoc_taglets_see_set_symbol (self, _tmp13_);
		_g_object_unref0 (_tmp13_);
	}
	_tmp14_ = self->priv->_symbol;
	if (_tmp14_ == NULL) {
		gchar* _tmp15_;
		gchar* _tmp16_;
		gchar* _tmp17_;
		gchar* _tmp18_;
		const gchar* _tmp19_;
		_tmp15_ = valadoc_api_node_get_full_name (container);
		_tmp16_ = _tmp15_;
		_tmp17_ = g_strdup_printf ("%s: %s: @see", file_path, _tmp16_);
		_tmp18_ = _tmp17_;
		_tmp19_ = self->priv->_symbol_name;
		valadoc_error_reporter_simple_warning (reporter, _tmp18_, "`%s' does not exist", _tmp19_);
		_g_free0 (_tmp18_);
		_g_free0 (_tmp16_);
	}
}

static void
valadoc_taglets_see_real_accept (ValadocContentContentElement* base,
                                 ValadocContentContentVisitor* visitor)
{
	ValadocTagletsSee * self;
	self = (ValadocTagletsSee*) base;
	g_return_if_fail (visitor != NULL);
	valadoc_content_content_visitor_visit_taglet (visitor, (ValadocContentTaglet*) self);
}

static gboolean
valadoc_taglets_see_real_is_empty (ValadocContentContentElement* base)
{
	ValadocTagletsSee * self;
	gboolean result = FALSE;
	self = (ValadocTagletsSee*) base;
	result = FALSE;
	return result;
}

static ValadocContentContentElement*
valadoc_taglets_see_real_copy (ValadocContentContentElement* base,
                               ValadocContentContentElement* new_parent)
{
	ValadocTagletsSee * self;
	ValadocTagletsSee* see = NULL;
	ValadocTagletsSee* _tmp0_;
	const gchar* _tmp1_;
	ValadocApiNode* _tmp2_;
	ValadocContentContentElement* result = NULL;
	self = (ValadocTagletsSee*) base;
	_tmp0_ = valadoc_taglets_see_new ();
	see = _tmp0_;
	valadoc_content_content_element_set_parent ((ValadocContentContentElement*) see, new_parent);
	_tmp1_ = self->priv->_symbol_name;
	valadoc_taglets_see_set_symbol_name (see, _tmp1_);
	_tmp2_ = self->priv->_symbol;
	valadoc_taglets_see_set_symbol (see, _tmp2_);
	result = (ValadocContentContentElement*) see;
	return result;
}

ValadocTagletsSee*
valadoc_taglets_see_construct (GType object_type)
{
	ValadocTagletsSee * self = NULL;
	self = (ValadocTagletsSee*) valadoc_content_content_element_construct (object_type);
	return self;
}

ValadocTagletsSee*
valadoc_taglets_see_new (void)
{
	return valadoc_taglets_see_construct (BALADOC_TAGLETS_TYPE_SEE);
}

static void
valadoc_taglets_see_class_init (ValadocTagletsSeeClass * klass,
                                gpointer klass_data)
{
	valadoc_taglets_see_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocTagletsSee_private_offset);
	((ValadocContentContentElementClass *) klass)->check = (void (*) (ValadocContentContentElement*, ValadocApiTree*, ValadocApiNode*, const gchar*, ValadocErrorReporter*, ValadocSettings*)) valadoc_taglets_see_real_check;
	((ValadocContentContentElementClass *) klass)->accept = (void (*) (ValadocContentContentElement*, ValadocContentContentVisitor*)) valadoc_taglets_see_real_accept;
	((ValadocContentContentElementClass *) klass)->is_empty = (gboolean (*) (ValadocContentContentElement*)) valadoc_taglets_see_real_is_empty;
	((ValadocContentContentElementClass *) klass)->copy = (ValadocContentContentElement* (*) (ValadocContentContentElement*, ValadocContentContentElement*)) valadoc_taglets_see_real_copy;
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_taglets_see_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_valadoc_taglets_see_set_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_taglets_see_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_TAGLETS_SEE_SYMBOL_NAME_PROPERTY, valadoc_taglets_see_properties[BALADOC_TAGLETS_SEE_SYMBOL_NAME_PROPERTY] = g_param_spec_string ("symbol-name", "symbol-name", "symbol-name", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_TAGLETS_SEE_SYMBOL_PROPERTY, valadoc_taglets_see_properties[BALADOC_TAGLETS_SEE_SYMBOL_PROPERTY] = g_param_spec_object ("symbol", "symbol", "symbol", BALADOC_API_TYPE_NODE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_taglets_see_valadoc_content_taglet_interface_init (ValadocContentTagletIface * iface,
                                                           gpointer iface_data)
{
	valadoc_taglets_see_valadoc_content_taglet_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_parser_rule = (ValadocRule* (*) (ValadocContentTaglet*, ValadocRule*)) valadoc_taglets_see_real_get_parser_rule;
}

static void
valadoc_taglets_see_valadoc_content_block_interface_init (ValadocContentBlockIface * iface,
                                                          gpointer iface_data)
{
	valadoc_taglets_see_valadoc_content_block_parent_iface = g_type_interface_peek_parent (iface);
}

static void
valadoc_taglets_see_instance_init (ValadocTagletsSee * self,
                                   gpointer klass)
{
	self->priv = valadoc_taglets_see_get_instance_private (self);
}

static void
valadoc_taglets_see_finalize (GObject * obj)
{
	ValadocTagletsSee * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_TAGLETS_TYPE_SEE, ValadocTagletsSee);
	_g_free0 (self->priv->_symbol_name);
	_g_object_unref0 (self->priv->_symbol);
	G_OBJECT_CLASS (valadoc_taglets_see_parent_class)->finalize (obj);
}

static GType
valadoc_taglets_see_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocTagletsSeeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_taglets_see_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocTagletsSee), 0, (GInstanceInitFunc) valadoc_taglets_see_instance_init, NULL };
	static const GInterfaceInfo valadoc_content_taglet_info = { (GInterfaceInitFunc) valadoc_taglets_see_valadoc_content_taglet_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	static const GInterfaceInfo valadoc_content_block_info = { (GInterfaceInitFunc) valadoc_taglets_see_valadoc_content_block_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType valadoc_taglets_see_type_id;
	valadoc_taglets_see_type_id = g_type_register_static (BALADOC_CONTENT_TYPE_CONTENT_ELEMENT, "ValadocTagletsSee", &g_define_type_info, 0);
	g_type_add_interface_static (valadoc_taglets_see_type_id, BALADOC_CONTENT_TYPE_TAGLET, &valadoc_content_taglet_info);
	g_type_add_interface_static (valadoc_taglets_see_type_id, BALADOC_CONTENT_TYPE_BLOCK, &valadoc_content_block_info);
	ValadocTagletsSee_private_offset = g_type_add_instance_private (valadoc_taglets_see_type_id, sizeof (ValadocTagletsSeePrivate));
	return valadoc_taglets_see_type_id;
}

GType
valadoc_taglets_see_get_type (void)
{
	static volatile gsize valadoc_taglets_see_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_taglets_see_type_id__volatile)) {
		GType valadoc_taglets_see_type_id;
		valadoc_taglets_see_type_id = valadoc_taglets_see_get_type_once ();
		g_once_init_leave (&valadoc_taglets_see_type_id__volatile, valadoc_taglets_see_type_id);
	}
	return valadoc_taglets_see_type_id__volatile;
}

static void
_vala_valadoc_taglets_see_get_property (GObject * object,
                                        guint property_id,
                                        GValue * value,
                                        GParamSpec * pspec)
{
	ValadocTagletsSee * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_TAGLETS_TYPE_SEE, ValadocTagletsSee);
	switch (property_id) {
		case BALADOC_TAGLETS_SEE_SYMBOL_NAME_PROPERTY:
		g_value_set_string (value, valadoc_taglets_see_get_symbol_name (self));
		break;
		case BALADOC_TAGLETS_SEE_SYMBOL_PROPERTY:
		g_value_set_object (value, valadoc_taglets_see_get_symbol (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_valadoc_taglets_see_set_property (GObject * object,
                                        guint property_id,
                                        const GValue * value,
                                        GParamSpec * pspec)
{
	ValadocTagletsSee * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_TAGLETS_TYPE_SEE, ValadocTagletsSee);
	switch (property_id) {
		case BALADOC_TAGLETS_SEE_SYMBOL_NAME_PROPERTY:
		valadoc_taglets_see_set_symbol_name (self, g_value_get_string (value));
		break;
		case BALADOC_TAGLETS_SEE_SYMBOL_PROPERTY:
		valadoc_taglets_see_set_symbol (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_array_destroy (gpointer array,
                     gint array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		gint i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}

static void
_vala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}

