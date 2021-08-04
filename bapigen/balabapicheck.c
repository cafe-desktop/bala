/* balavapicheck.c generated by balac, the Bala compiler
 * generated from balavapicheck.bala, do not modify */

/* balavapicheck.bala
 *
 * Copyright (C) 2007  Mathias Hasselmann
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
 * 	Mathias Hasselmann <mathias.hasselmann@gmx.de>
 */

#include <glib-object.h>
#include <bala.h>
#include <balagee.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gidlmodule.h>
#include <gidlparser.h>
#include <gidlnode.h>
#include <stdio.h>
#include <glib/gstdio.h>
#include <gobject/gvaluecollector.h>

#define BALA_TYPE_VAPI_CHECK (bala_vapi_check_get_type ())
#define BALA_VAPI_CHECK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BALA_TYPE_VAPI_CHECK, BalaVAPICheck))
#define BALA_VAPI_CHECK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BALA_TYPE_VAPI_CHECK, BalaVAPICheckClass))
#define BALA_IS_VAPI_CHECK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BALA_TYPE_VAPI_CHECK))
#define BALA_IS_VAPI_CHECK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BALA_TYPE_VAPI_CHECK))
#define BALA_VAPI_CHECK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BALA_TYPE_VAPI_CHECK, BalaVAPICheckClass))

typedef struct _BalaVAPICheck BalaVAPICheck;
typedef struct _BalaVAPICheckClass BalaVAPICheckClass;
typedef struct _BalaVAPICheckPrivate BalaVAPICheckPrivate;
#define _bala_source_file_unref0(var) ((var == NULL) ? NULL : (var = (bala_source_file_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_code_context_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_context_unref (var), NULL)))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_io_channel_unref0(var) ((var == NULL) ? NULL : (var = (g_io_channel_unref (var), NULL)))
#define _bala_source_reference_unref0(var) ((var == NULL) ? NULL : (var = (bala_source_reference_unref (var), NULL)))
#define _bala_vapi_check_unref0(var) ((var == NULL) ? NULL : (var = (bala_vapi_check_unref (var), NULL)))
typedef struct _BalaParamSpecVAPICheck BalaParamSpecVAPICheck;

struct _BalaVAPICheck {
	GTypeInstance parent_instance;
	volatile int ref_count;
	BalaVAPICheckPrivate * priv;
};

struct _BalaVAPICheckClass {
	GTypeClass parent_class;
	void (*finalize) (BalaVAPICheck *self);
};

struct _BalaVAPICheckPrivate {
	BalaCodeContext* _context;
	BalaSourceFile* _gidl;
	BalaSourceFile* _metadata;
	BalaList* _scope;
	BalaSet* _symbols;
};

struct _BalaParamSpecVAPICheck {
	GParamSpec parent_instance;
};

static gint BalaVAPICheck_private_offset;
static gpointer bala_vapi_check_parent_class = NULL;

G_GNUC_INTERNAL gpointer bala_vapi_check_ref (gpointer instance);
G_GNUC_INTERNAL void bala_vapi_check_unref (gpointer instance);
G_GNUC_INTERNAL GParamSpec* bala_param_spec_vapi_check (const gchar* name,
                                        const gchar* nick,
                                        const gchar* blurb,
                                        GType object_type,
                                        GParamFlags flags);
G_GNUC_INTERNAL void bala_value_set_vapi_check (GValue* value,
                                gpointer v_object) G_GNUC_UNUSED;
G_GNUC_INTERNAL void bala_value_take_vapi_check (GValue* value,
                                 gpointer v_object);
G_GNUC_INTERNAL gpointer bala_value_get_vapi_check (const GValue* value) G_GNUC_UNUSED;
G_GNUC_INTERNAL GType bala_vapi_check_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BalaVAPICheck, bala_vapi_check_unref)
G_GNUC_INTERNAL BalaVAPICheck* bala_vapi_check_new (const gchar* gidlname,
                                    BalaCodeContext* context);
G_GNUC_INTERNAL BalaVAPICheck* bala_vapi_check_construct (GType object_type,
                                          const gchar* gidlname,
                                          BalaCodeContext* context);
static void bala_vapi_check_set_gidl (BalaVAPICheck* self,
                               BalaSourceFile* value);
static void bala_vapi_check_set_metadata (BalaVAPICheck* self,
                                   BalaSourceFile* value);
static void bala_vapi_check_set_context (BalaVAPICheck* self,
                                  BalaCodeContext* value);
G_GNUC_INTERNAL BalaCodeContext* bala_vapi_check_get_context (BalaVAPICheck* self);
G_GNUC_INTERNAL BalaSourceFile* bala_vapi_check_get_gidl (BalaVAPICheck* self);
G_GNUC_INTERNAL BalaSourceFile* bala_vapi_check_get_metadata (BalaVAPICheck* self);
static void bala_vapi_check_parse_gidl (BalaVAPICheck* self);
static void bala_vapi_check_parse_members (BalaVAPICheck* self,
                                    const gchar* name,
                                    GList* members);
static void _g_idl_module_free0_ (gpointer var);
static inline void _g_list_free__g_idl_module_free0_ (GList* self);
static void bala_vapi_check_add_symbol (BalaVAPICheck* self,
                                 const gchar* name,
                                 const gchar* separator);
static gchar* bala_vapi_check_get_scope (BalaVAPICheck* self);
static void bala_vapi_check_enter_scope (BalaVAPICheck* self,
                                  const gchar* name);
static void bala_vapi_check_leave_scope (BalaVAPICheck* self);
static gint bala_vapi_check_check_metadata (BalaVAPICheck* self);
G_GNUC_INTERNAL gint bala_vapi_check_run (BalaVAPICheck* self);
static gint bala_vapi_check_main (gchar** args,
                           gint args_length1);
static void bala_vapi_check_finalize (BalaVAPICheck * obj);
static GType bala_vapi_check_get_type_once (void);
static void _bala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _bala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);
static gint _bala_array_length (gpointer array);

static inline gpointer
bala_vapi_check_get_instance_private (BalaVAPICheck* self)
{
	return G_STRUCT_MEMBER_P (self, BalaVAPICheck_private_offset);
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

G_GNUC_INTERNAL BalaVAPICheck*
bala_vapi_check_construct (GType object_type,
                           const gchar* gidlname,
                           BalaCodeContext* context)
{
	BalaVAPICheck* self = NULL;
	BalaSourceFile* _tmp0_;
	BalaSourceFile* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	BalaSourceFile* _tmp8_;
	BalaSourceFile* _tmp9_;
	g_return_val_if_fail (gidlname != NULL, NULL);
	g_return_val_if_fail (context != NULL, NULL);
	self = (BalaVAPICheck*) g_type_create_instance (object_type);
	_tmp0_ = bala_source_file_new (context, BALA_SOURCE_FILE_TYPE_SOURCE, gidlname, NULL, FALSE);
	_tmp1_ = _tmp0_;
	bala_vapi_check_set_gidl (self, _tmp1_);
	_bala_source_file_unref0 (_tmp1_);
	_tmp2_ = strlen (gidlname);
	_tmp3_ = _tmp2_;
	_tmp4_ = string_substring (gidlname, (glong) 0, (glong) (_tmp3_ - 5));
	_tmp5_ = _tmp4_;
	_tmp6_ = g_strconcat (_tmp5_, ".metadata", NULL);
	_tmp7_ = _tmp6_;
	_tmp8_ = bala_source_file_new (context, BALA_SOURCE_FILE_TYPE_SOURCE, _tmp7_, NULL, FALSE);
	_tmp9_ = _tmp8_;
	bala_vapi_check_set_metadata (self, _tmp9_);
	_bala_source_file_unref0 (_tmp9_);
	_g_free0 (_tmp7_);
	_g_free0 (_tmp5_);
	bala_vapi_check_set_context (self, context);
	return self;
}

G_GNUC_INTERNAL BalaVAPICheck*
bala_vapi_check_new (const gchar* gidlname,
                     BalaCodeContext* context)
{
	return bala_vapi_check_construct (BALA_TYPE_VAPI_CHECK, gidlname, context);
}

G_GNUC_INTERNAL BalaCodeContext*
bala_vapi_check_get_context (BalaVAPICheck* self)
{
	BalaCodeContext* result;
	BalaCodeContext* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_context;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_code_context_ref0 (gpointer self)
{
	return self ? bala_code_context_ref (self) : NULL;
}

static void
bala_vapi_check_set_context (BalaVAPICheck* self,
                             BalaCodeContext* value)
{
	BalaCodeContext* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_code_context_ref0 (value);
	_bala_code_context_unref0 (self->priv->_context);
	self->priv->_context = _tmp0_;
}

G_GNUC_INTERNAL BalaSourceFile*
bala_vapi_check_get_gidl (BalaVAPICheck* self)
{
	BalaSourceFile* result;
	BalaSourceFile* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_gidl;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_source_file_ref0 (gpointer self)
{
	return self ? bala_source_file_ref (self) : NULL;
}

static void
bala_vapi_check_set_gidl (BalaVAPICheck* self,
                          BalaSourceFile* value)
{
	BalaSourceFile* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_source_file_ref0 (value);
	_bala_source_file_unref0 (self->priv->_gidl);
	self->priv->_gidl = _tmp0_;
}

G_GNUC_INTERNAL BalaSourceFile*
bala_vapi_check_get_metadata (BalaVAPICheck* self)
{
	BalaSourceFile* result;
	BalaSourceFile* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_metadata;
	result = _tmp0_;
	return result;
}

static void
bala_vapi_check_set_metadata (BalaVAPICheck* self,
                              BalaSourceFile* value)
{
	BalaSourceFile* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_source_file_ref0 (value);
	_bala_source_file_unref0 (self->priv->_metadata);
	self->priv->_metadata = _tmp0_;
}

static void
_g_idl_module_free0_ (gpointer var)
{
	(var == NULL) ? NULL : (var = (g_idl_module_free (var), NULL));
}

static inline void
_g_list_free__g_idl_module_free0_ (GList* self)
{
	g_list_free_full (self, (GDestroyNotify) _g_idl_module_free0_);
}

static void
bala_vapi_check_parse_gidl (BalaVAPICheck* self)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	GHashFunc _tmp2_;
	GEqualFunc _tmp3_;
	BalaHashSet* _tmp4_;
	GError* _inner_error0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, _tmp0_);
	_bala_iterable_unref0 (self->priv->_scope);
	self->priv->_scope = (BalaList*) _tmp1_;
	_tmp2_ = g_str_hash;
	_tmp3_ = g_str_equal;
	_tmp4_ = bala_hash_set_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, _tmp2_, _tmp3_);
	_bala_iterable_unref0 (self->priv->_symbols);
	self->priv->_symbols = (BalaSet*) _tmp4_;
	{
		GList* _tmp5_ = NULL;
		BalaSourceFile* _tmp6_;
		const gchar* _tmp7_;
		const gchar* _tmp8_;
		GList* _tmp9_;
		_tmp6_ = self->priv->_gidl;
		_tmp7_ = bala_source_file_get_filename (_tmp6_);
		_tmp8_ = _tmp7_;
		_tmp9_ = g_idl_parse_file (_tmp8_, &_inner_error0_);
		_tmp5_ = _tmp9_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == G_MARKUP_ERROR) {
				goto __catch0_g_markup_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return;
		}
		{
			GList* module_collection = NULL;
			GList* module_it = NULL;
			module_collection = _tmp5_;
			for (module_it = module_collection; module_it != NULL; module_it = module_it->next) {
				GIdlModule* module = NULL;
				module = (GIdlModule*) module_it->data;
				{
					GIdlModule* _tmp10_;
					const gchar* _tmp11_;
					GIdlModule* _tmp12_;
					GList* _tmp13_;
					_tmp10_ = module;
					_tmp11_ = _tmp10_->name;
					_tmp12_ = module;
					_tmp13_ = _tmp12_->entries;
					bala_vapi_check_parse_members (self, _tmp11_, _tmp13_);
				}
			}
		}
		(_tmp5_ == NULL) ? NULL : (_tmp5_ = (_g_list_free__g_idl_module_free0_ (_tmp5_), NULL));
	}
	goto __finally0;
	__catch0_g_markup_error:
	{
		GError* e = NULL;
		FILE* _tmp14_;
		BalaSourceFile* _tmp15_;
		const gchar* _tmp16_;
		const gchar* _tmp17_;
		GError* _tmp18_;
		const gchar* _tmp19_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp14_ = stderr;
		_tmp15_ = self->priv->_gidl;
		_tmp16_ = bala_source_file_get_filename (_tmp15_);
		_tmp17_ = _tmp16_;
		_tmp18_ = e;
		_tmp19_ = _tmp18_->message;
		fprintf (_tmp14_, "%s: %s\n", _tmp17_, _tmp19_);
		_g_error_free0 (e);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return;
	}
}

static void
bala_vapi_check_add_symbol (BalaVAPICheck* self,
                            const gchar* name,
                            const gchar* separator)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	if (NULL != separator) {
		gchar* fullname = NULL;
		gchar* _tmp0_;
		gchar* _tmp1_;
		gchar* _tmp2_;
		gchar* _tmp3_;
		gchar* _tmp4_;
		gchar* _tmp5_;
		BalaSet* _tmp6_;
		const gchar* _tmp7_;
		_tmp0_ = bala_vapi_check_get_scope (self);
		_tmp1_ = _tmp0_;
		_tmp2_ = g_strconcat (_tmp1_, separator, NULL);
		_tmp3_ = _tmp2_;
		_tmp4_ = g_strconcat (_tmp3_, name, NULL);
		_tmp5_ = _tmp4_;
		_g_free0 (_tmp3_);
		_g_free0 (_tmp1_);
		fullname = _tmp5_;
		_tmp6_ = self->priv->_symbols;
		_tmp7_ = fullname;
		bala_collection_add ((BalaCollection*) _tmp6_, _tmp7_);
		_g_free0 (fullname);
	} else {
		BalaSet* _tmp8_;
		_tmp8_ = self->priv->_symbols;
		bala_collection_add ((BalaCollection*) _tmp8_, name);
	}
}

static gchar*
bala_vapi_check_get_scope (BalaVAPICheck* self)
{
	BalaList* _tmp0_;
	BalaList* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gpointer _tmp4_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_scope;
	_tmp1_ = self->priv->_scope;
	_tmp2_ = bala_collection_get_size ((BalaCollection*) _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = bala_list_get (_tmp0_, _tmp3_ - 1);
	result = (gchar*) _tmp4_;
	return result;
}

static void
bala_vapi_check_enter_scope (BalaVAPICheck* self,
                             const gchar* name)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	_tmp0_ = self->priv->_scope;
	bala_collection_add ((BalaCollection*) _tmp0_, name);
	bala_vapi_check_add_symbol (self, name, NULL);
}

static void
bala_vapi_check_leave_scope (BalaVAPICheck* self)
{
	BalaList* _tmp0_;
	BalaList* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gpointer _tmp4_;
	gchar* _tmp5_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_scope;
	_tmp1_ = self->priv->_scope;
	_tmp2_ = bala_collection_get_size ((BalaCollection*) _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = bala_list_remove_at (_tmp0_, _tmp3_ - 1);
	_tmp5_ = (gchar*) _tmp4_;
	_g_free0 (_tmp5_);
}

static void
bala_vapi_check_parse_members (BalaVAPICheck* self,
                               const gchar* name,
                               GList* members)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	bala_vapi_check_enter_scope (self, name);
	{
		GList* node_collection = NULL;
		GList* node_it = NULL;
		node_collection = members;
		for (node_it = node_collection; node_it != NULL; node_it = node_it->next) {
			GIdlNode* node = NULL;
			node = (GIdlNode*) node_it->data;
			{
				GIdlNode* _tmp0_;
				GIdlNodeTypeId _tmp1_;
				_tmp0_ = node;
				_tmp1_ = _tmp0_->type;
				switch (_tmp1_) {
					case G_IDL_NODE_ENUM:
					{
						GIdlNode* _tmp2_;
						const gchar* _tmp3_;
						GIdlNode* _tmp4_;
						GList* _tmp5_;
						_tmp2_ = node;
						_tmp3_ = ((GIdlNodeEnum*) _tmp2_)->gtype_name;
						_tmp4_ = node;
						_tmp5_ = ((GIdlNodeEnum*) _tmp4_)->values;
						bala_vapi_check_parse_members (self, _tmp3_, _tmp5_);
						break;
					}
					case G_IDL_NODE_FUNCTION:
					{
						GIdlNode* _tmp6_;
						const gchar* _tmp7_;
						GIdlNode* _tmp8_;
						GList* _tmp9_;
						_tmp6_ = node;
						_tmp7_ = ((GIdlNodeFunction*) _tmp6_)->symbol;
						_tmp8_ = node;
						_tmp9_ = ((GIdlNodeFunction*) _tmp8_)->parameters;
						bala_vapi_check_parse_members (self, _tmp7_, (GList*) _tmp9_);
						break;
					}
					case G_IDL_NODE_BOXED:
					{
						GIdlNode* _tmp10_;
						const gchar* _tmp11_;
						GIdlNode* _tmp12_;
						GList* _tmp13_;
						_tmp10_ = node;
						_tmp11_ = ((GIdlNodeBoxed*) _tmp10_)->gtype_name;
						_tmp12_ = node;
						_tmp13_ = ((GIdlNodeBoxed*) _tmp12_)->members;
						bala_vapi_check_parse_members (self, _tmp11_, _tmp13_);
						break;
					}
					case G_IDL_NODE_INTERFACE:
					case G_IDL_NODE_OBJECT:
					{
						GIdlNode* _tmp14_;
						const gchar* _tmp15_;
						GIdlNode* _tmp16_;
						GList* _tmp17_;
						_tmp14_ = node;
						_tmp15_ = ((GIdlNodeInterface*) _tmp14_)->gtype_name;
						_tmp16_ = node;
						_tmp17_ = ((GIdlNodeInterface*) _tmp16_)->members;
						bala_vapi_check_parse_members (self, _tmp15_, _tmp17_);
						break;
					}
					case G_IDL_NODE_FIELD:
					case G_IDL_NODE_PARAM:
					{
						GIdlNode* _tmp18_;
						const gchar* _tmp19_;
						_tmp18_ = node;
						_tmp19_ = _tmp18_->name;
						bala_vapi_check_add_symbol (self, _tmp19_, ".");
						break;
					}
					case G_IDL_NODE_PROPERTY:
					case G_IDL_NODE_SIGNAL:
					{
						GIdlNode* _tmp20_;
						const gchar* _tmp21_;
						_tmp20_ = node;
						_tmp21_ = _tmp20_->name;
						bala_vapi_check_add_symbol (self, _tmp21_, "::");
						break;
					}
					case G_IDL_NODE_STRUCT:
					{
						GIdlNode* _tmp22_;
						const gchar* _tmp23_;
						GIdlNode* _tmp24_;
						GList* _tmp25_;
						_tmp22_ = node;
						_tmp23_ = _tmp22_->name;
						_tmp24_ = node;
						_tmp25_ = ((GIdlNodeStruct*) _tmp24_)->members;
						bala_vapi_check_parse_members (self, _tmp23_, _tmp25_);
						break;
					}
					case G_IDL_NODE_VALUE:
					case G_IDL_NODE_VFUNC:
					{
						break;
					}
					default:
					{
						GIdlNode* _tmp26_;
						const gchar* _tmp27_;
						GIdlNode* _tmp28_;
						GIdlNodeTypeId _tmp29_;
						_tmp26_ = node;
						_tmp27_ = _tmp26_->name;
						_tmp28_ = node;
						_tmp29_ = _tmp28_->type;
						g_warning ("balavapicheck.bala:121: TODO: %s: Implement support for type %d nodes", _tmp27_, (gint) _tmp29_);
						break;
					}
				}
			}
		}
	}
	bala_vapi_check_leave_scope (self);
}

static gint
bala_vapi_check_check_metadata (BalaVAPICheck* self)
{
	gint _tmp38_ = -1;
	GError* _inner_error0_ = NULL;
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	{
		GIOChannel* metafile = NULL;
		BalaSourceFile* _tmp0_;
		const gchar* _tmp1_;
		const gchar* _tmp2_;
		GIOChannel* _tmp3_;
		gchar* line = NULL;
		gint lineno = 0;
		_tmp0_ = self->priv->_metadata;
		_tmp1_ = bala_source_file_get_filename (_tmp0_);
		_tmp2_ = _tmp1_;
		_tmp3_ = g_io_channel_new_file (_tmp2_, "r", &_inner_error0_);
		metafile = _tmp3_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
		lineno = 1;
		while (TRUE) {
			GIOStatus _tmp4_ = 0;
			GIOChannel* _tmp5_;
			gchar* _tmp6_ = NULL;
			GIOStatus _tmp7_;
			gchar** tokens = NULL;
			const gchar* _tmp8_;
			gchar** _tmp9_;
			gchar** _tmp10_;
			gint tokens_length1;
			gint _tokens_size_;
			gchar* symbol = NULL;
			gchar** _tmp11_;
			gint _tmp11__length1;
			const gchar* _tmp12_;
			gchar* _tmp13_;
			gboolean _tmp14_ = FALSE;
			const gchar* _tmp15_;
			gint _tmp16_;
			gint _tmp17_;
			_tmp5_ = metafile;
			_tmp7_ = g_io_channel_read_line (_tmp5_, &_tmp6_, NULL, NULL, &_inner_error0_);
			_g_free0 (line);
			line = _tmp6_;
			_tmp4_ = _tmp7_;
			if (G_UNLIKELY (_inner_error0_ != NULL)) {
				_g_free0 (line);
				_g_io_channel_unref0 (metafile);
				goto __catch0_g_error;
			}
			if (!(G_IO_STATUS_NORMAL == _tmp4_)) {
				break;
			}
			_tmp8_ = line;
			_tmp10_ = _tmp9_ = g_strsplit (_tmp8_, " ", 2);
			tokens = _tmp10_;
			tokens_length1 = _bala_array_length (_tmp9_);
			_tokens_size_ = tokens_length1;
			_tmp11_ = tokens;
			_tmp11__length1 = tokens_length1;
			_tmp12_ = _tmp11_[0];
			_tmp13_ = g_strdup (_tmp12_);
			symbol = _tmp13_;
			_tmp15_ = symbol;
			_tmp16_ = strlen (_tmp15_);
			_tmp17_ = _tmp16_;
			if (_tmp17_ > 0) {
				BalaSet* _tmp18_;
				const gchar* _tmp19_;
				_tmp18_ = self->priv->_symbols;
				_tmp19_ = symbol;
				_tmp14_ = !bala_collection_contains ((BalaCollection*) _tmp18_, _tmp19_);
			} else {
				_tmp14_ = FALSE;
			}
			if (_tmp14_) {
				BalaSourceReference* src = NULL;
				BalaSourceFile* _tmp20_;
				BalaSourceLocation _tmp21_ = {0};
				const gchar* _tmp22_;
				gint _tmp23_;
				gint _tmp24_;
				BalaSourceLocation _tmp25_ = {0};
				BalaSourceReference* _tmp26_;
				BalaSourceReference* _tmp27_;
				const gchar* _tmp28_;
				gchar* _tmp29_;
				gchar* _tmp30_;
				_tmp20_ = self->priv->_metadata;
				bala_source_location_init (&_tmp21_, NULL, lineno, 1);
				_tmp22_ = symbol;
				_tmp23_ = strlen (_tmp22_);
				_tmp24_ = _tmp23_;
				bala_source_location_init (&_tmp25_, NULL, lineno, (gint) _tmp24_);
				_tmp26_ = bala_source_reference_new (_tmp20_, &_tmp21_, &_tmp25_);
				src = _tmp26_;
				_tmp27_ = src;
				_tmp28_ = symbol;
				_tmp29_ = g_strdup_printf ("Symbol `%s' not found", _tmp28_);
				_tmp30_ = _tmp29_;
				bala_report_error (_tmp27_, _tmp30_);
				_g_free0 (_tmp30_);
				_bala_source_reference_unref0 (src);
			}
			lineno += 1;
			_g_free0 (symbol);
			tokens = (_bala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
		}
		result = 0;
		_g_free0 (line);
		_g_io_channel_unref0 (metafile);
		return result;
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* _error_ = NULL;
		BalaSourceFile* _tmp31_;
		const gchar* _tmp32_;
		const gchar* _tmp33_;
		GError* _tmp34_;
		const gchar* _tmp35_;
		gchar* _tmp36_;
		gchar* _tmp37_;
		_error_ = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp31_ = self->priv->_metadata;
		_tmp32_ = bala_source_file_get_filename (_tmp31_);
		_tmp33_ = _tmp32_;
		_tmp34_ = _error_;
		_tmp35_ = _tmp34_->message;
		_tmp36_ = g_strdup_printf ("%s: %s", _tmp33_, _tmp35_);
		_tmp37_ = _tmp36_;
		bala_report_error (NULL, _tmp37_);
		_g_free0 (_tmp37_);
		result = 1;
		_g_error_free0 (_error_);
		return result;
	}
	__finally0:
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
	g_clear_error (&_inner_error0_);
	return _tmp38_;
}

G_GNUC_INTERNAL gint
bala_vapi_check_run (BalaVAPICheck* self)
{
	BalaSourceFile* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	BalaSourceFile* _tmp8_;
	const gchar* _tmp9_;
	const gchar* _tmp10_;
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_gidl;
	_tmp1_ = bala_source_file_get_filename (_tmp0_);
	_tmp2_ = _tmp1_;
	if (!g_file_test (_tmp2_, G_FILE_TEST_IS_REGULAR)) {
		BalaSourceFile* _tmp3_;
		const gchar* _tmp4_;
		const gchar* _tmp5_;
		gchar* _tmp6_;
		gchar* _tmp7_;
		_tmp3_ = self->priv->_gidl;
		_tmp4_ = bala_source_file_get_filename (_tmp3_);
		_tmp5_ = _tmp4_;
		_tmp6_ = g_strdup_printf ("%s not found", _tmp5_);
		_tmp7_ = _tmp6_;
		bala_report_error (NULL, _tmp7_);
		_g_free0 (_tmp7_);
		result = 2;
		return result;
	}
	_tmp8_ = self->priv->_metadata;
	_tmp9_ = bala_source_file_get_filename (_tmp8_);
	_tmp10_ = _tmp9_;
	if (!g_file_test (_tmp10_, G_FILE_TEST_IS_REGULAR)) {
		BalaSourceFile* _tmp11_;
		const gchar* _tmp12_;
		const gchar* _tmp13_;
		gchar* _tmp14_;
		gchar* _tmp15_;
		_tmp11_ = self->priv->_metadata;
		_tmp12_ = bala_source_file_get_filename (_tmp11_);
		_tmp13_ = _tmp12_;
		_tmp14_ = g_strdup_printf ("%s not found", _tmp13_);
		_tmp15_ = _tmp14_;
		bala_report_error (NULL, _tmp15_);
		_g_free0 (_tmp15_);
		result = 2;
		return result;
	}
	bala_vapi_check_parse_gidl (self);
	result = bala_vapi_check_check_metadata (self);
	return result;
}

static gint
bala_vapi_check_main (gchar** args,
                      gint args_length1)
{
	gboolean _tmp0_ = FALSE;
	BalaVAPICheck* vapicheck = NULL;
	const gchar* _tmp6_;
	BalaCodeContext* _tmp7_;
	BalaCodeContext* _tmp8_;
	BalaVAPICheck* _tmp9_;
	BalaVAPICheck* _tmp10_;
	BalaVAPICheck* _tmp11_;
	gint result = 0;
	if (2 != args_length1) {
		_tmp0_ = TRUE;
	} else {
		const gchar* _tmp1_;
		_tmp1_ = args[1];
		_tmp0_ = !g_str_has_suffix (_tmp1_, ".gidl");
	}
	if (_tmp0_) {
		FILE* _tmp2_;
		const gchar* _tmp3_;
		gchar* _tmp4_;
		gchar* _tmp5_;
		_tmp2_ = stdout;
		_tmp3_ = args[0];
		_tmp4_ = g_path_get_basename (_tmp3_);
		_tmp5_ = _tmp4_;
		fprintf (_tmp2_, "Usage: %s library.gidl\n", _tmp5_);
		_g_free0 (_tmp5_);
		result = 2;
		return result;
	}
	_tmp6_ = args[1];
	_tmp7_ = bala_code_context_new ();
	_tmp8_ = _tmp7_;
	_tmp9_ = bala_vapi_check_new (_tmp6_, _tmp8_);
	_tmp10_ = _tmp9_;
	_bala_code_context_unref0 (_tmp8_);
	vapicheck = _tmp10_;
	_tmp11_ = vapicheck;
	result = bala_vapi_check_run (_tmp11_);
	_bala_vapi_check_unref0 (vapicheck);
	return result;
}

int
main (int argc,
      char ** argv)
{
	return bala_vapi_check_main (argv, argc);
}

static void
bala_value_vapi_check_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
bala_value_vapi_check_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		bala_vapi_check_unref (value->data[0].v_pointer);
	}
}

static void
bala_value_vapi_check_copy_value (const GValue* src_value,
                                  GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = bala_vapi_check_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
bala_value_vapi_check_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
bala_value_vapi_check_collect_value (GValue* value,
                                     guint n_collect_values,
                                     GTypeCValue* collect_values,
                                     guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		BalaVAPICheck * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = bala_vapi_check_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
bala_value_vapi_check_lcopy_value (const GValue* value,
                                   guint n_collect_values,
                                   GTypeCValue* collect_values,
                                   guint collect_flags)
{
	BalaVAPICheck ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = bala_vapi_check_ref (value->data[0].v_pointer);
	}
	return NULL;
}

G_GNUC_INTERNAL GParamSpec*
bala_param_spec_vapi_check (const gchar* name,
                            const gchar* nick,
                            const gchar* blurb,
                            GType object_type,
                            GParamFlags flags)
{
	BalaParamSpecVAPICheck* spec;
	g_return_val_if_fail (g_type_is_a (object_type, BALA_TYPE_VAPI_CHECK), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

G_GNUC_INTERNAL gpointer
bala_value_get_vapi_check (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_VAPI_CHECK), NULL);
	return value->data[0].v_pointer;
}

G_GNUC_INTERNAL void
bala_value_set_vapi_check (GValue* value,
                           gpointer v_object)
{
	BalaVAPICheck * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_VAPI_CHECK));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_VAPI_CHECK));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		bala_vapi_check_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		bala_vapi_check_unref (old);
	}
}

G_GNUC_INTERNAL void
bala_value_take_vapi_check (GValue* value,
                            gpointer v_object)
{
	BalaVAPICheck * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_VAPI_CHECK));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_VAPI_CHECK));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		bala_vapi_check_unref (old);
	}
}

static void
bala_vapi_check_class_init (BalaVAPICheckClass * klass,
                            gpointer klass_data)
{
	bala_vapi_check_parent_class = g_type_class_peek_parent (klass);
	((BalaVAPICheckClass *) klass)->finalize = bala_vapi_check_finalize;
	g_type_class_adjust_private_offset (klass, &BalaVAPICheck_private_offset);
}

static void
bala_vapi_check_instance_init (BalaVAPICheck * self,
                               gpointer klass)
{
	self->priv = bala_vapi_check_get_instance_private (self);
	self->ref_count = 1;
}

static void
bala_vapi_check_finalize (BalaVAPICheck * obj)
{
	BalaVAPICheck * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_VAPI_CHECK, BalaVAPICheck);
	g_signal_handlers_destroy (self);
	_bala_code_context_unref0 (self->priv->_context);
	_bala_source_file_unref0 (self->priv->_gidl);
	_bala_source_file_unref0 (self->priv->_metadata);
	_bala_iterable_unref0 (self->priv->_scope);
	_bala_iterable_unref0 (self->priv->_symbols);
}

static GType
bala_vapi_check_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { bala_value_vapi_check_init, bala_value_vapi_check_free_value, bala_value_vapi_check_copy_value, bala_value_vapi_check_peek_pointer, "p", bala_value_vapi_check_collect_value, "p", bala_value_vapi_check_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (BalaVAPICheckClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_vapi_check_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaVAPICheck), 0, (GInstanceInitFunc) bala_vapi_check_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType bala_vapi_check_type_id;
	bala_vapi_check_type_id = g_type_register_fundamental (g_type_fundamental_next (), "BalaVAPICheck", &g_define_type_info, &g_define_type_fundamental_info, 0);
	BalaVAPICheck_private_offset = g_type_add_instance_private (bala_vapi_check_type_id, sizeof (BalaVAPICheckPrivate));
	return bala_vapi_check_type_id;
}

G_GNUC_INTERNAL GType
bala_vapi_check_get_type (void)
{
	static volatile gsize bala_vapi_check_type_id__volatile = 0;
	if (g_once_init_enter (&bala_vapi_check_type_id__volatile)) {
		GType bala_vapi_check_type_id;
		bala_vapi_check_type_id = bala_vapi_check_get_type_once ();
		g_once_init_leave (&bala_vapi_check_type_id__volatile, bala_vapi_check_type_id);
	}
	return bala_vapi_check_type_id__volatile;
}

G_GNUC_INTERNAL gpointer
bala_vapi_check_ref (gpointer instance)
{
	BalaVAPICheck * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

G_GNUC_INTERNAL void
bala_vapi_check_unref (gpointer instance)
{
	BalaVAPICheck * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		BALA_VAPI_CHECK_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

static void
_bala_array_destroy (gpointer array,
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
_bala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_bala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}

static gint
_bala_array_length (gpointer array)
{
	gint length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}

