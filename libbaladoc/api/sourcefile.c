/* sourcefile.c generated by balac, the Bala compiler
 * generated from sourcefile.bala, do not modify */

/* sourcefile.bala
 *
 * Copyright (C) 2011 Florian Brosch
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
 * 	Brosch Florian <flo.brosch@gmail.com>
 */

#include "baladoc.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <bala.h>
#include <glib-object.h>

enum  {
	BALADOC_API_SOURCE_FILE_0_PROPERTY,
	BALADOC_API_SOURCE_FILE_PACKAGE_PROPERTY,
	BALADOC_API_SOURCE_FILE_RELATIVE_PATH_PROPERTY,
	BALADOC_API_SOURCE_FILE_RELATIVE_C_PATH_PROPERTY,
	BALADOC_API_SOURCE_FILE_DATA_PROPERTY,
	BALADOC_API_SOURCE_FILE_NUM_PROPERTIES
};
static GParamSpec* baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_source_file_unref0(var) ((var == NULL) ? NULL : (var = (bala_source_file_unref (var), NULL)))

struct _BaladocApiSourceFilePrivate {
	BaladocApiPackage* _package;
	gchar* _relative_path;
	gchar* _relative_c_path;
	BalaSourceFile* _data;
};

static gint BaladocApiSourceFile_private_offset;
static gpointer baladoc_api_source_file_parent_class = NULL;

static void baladoc_api_source_file_set_package (BaladocApiSourceFile* self,
                                          BaladocApiPackage* value);
static void baladoc_api_source_file_set_relative_path (BaladocApiSourceFile* self,
                                                const gchar* value);
static void baladoc_api_source_file_set_relative_c_path (BaladocApiSourceFile* self,
                                                  const gchar* value);
static void baladoc_api_source_file_set_data (BaladocApiSourceFile* self,
                                       BalaSourceFile* value);
static void baladoc_api_source_file_finalize (GObject * obj);
static GType baladoc_api_source_file_get_type_once (void);
static void _bala_baladoc_api_source_file_get_property (GObject * object,
                                                 guint property_id,
                                                 GValue * value,
                                                 GParamSpec * pspec);
static void _bala_baladoc_api_source_file_set_property (GObject * object,
                                                 guint property_id,
                                                 const GValue * value,
                                                 GParamSpec * pspec);

static inline gpointer
baladoc_api_source_file_get_instance_private (BaladocApiSourceFile* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocApiSourceFile_private_offset);
}

BaladocApiPackage*
baladoc_api_source_file_get_package (BaladocApiSourceFile* self)
{
	BaladocApiPackage* result;
	BaladocApiPackage* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_package;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
baladoc_api_source_file_set_package (BaladocApiSourceFile* self,
                                     BaladocApiPackage* value)
{
	BaladocApiPackage* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_source_file_get_package (self);
	if (old_value != value) {
		BaladocApiPackage* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_package);
		self->priv->_package = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_PACKAGE_PROPERTY]);
	}
}

const gchar*
baladoc_api_source_file_get_relative_path (BaladocApiSourceFile* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_relative_path;
	result = _tmp0_;
	return result;
}

static void
baladoc_api_source_file_set_relative_path (BaladocApiSourceFile* self,
                                           const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_source_file_get_relative_path (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_relative_path);
		self->priv->_relative_path = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_RELATIVE_PATH_PROPERTY]);
	}
}

const gchar*
baladoc_api_source_file_get_relative_c_path (BaladocApiSourceFile* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_relative_c_path;
	result = _tmp0_;
	return result;
}

static void
baladoc_api_source_file_set_relative_c_path (BaladocApiSourceFile* self,
                                             const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_source_file_get_relative_c_path (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_relative_c_path);
		self->priv->_relative_c_path = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_RELATIVE_C_PATH_PROPERTY]);
	}
}

gchar*
baladoc_api_source_file_get_name (BaladocApiSourceFile* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_relative_path;
	_tmp1_ = g_path_get_basename (_tmp0_);
	result = _tmp1_;
	return result;
}

BalaSourceFile*
baladoc_api_source_file_get_data (BaladocApiSourceFile* self)
{
	BalaSourceFile* result;
	BalaSourceFile* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_data;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_source_file_ref0 (gpointer self)
{
	return self ? bala_source_file_ref (self) : NULL;
}

static void
baladoc_api_source_file_set_data (BaladocApiSourceFile* self,
                                  BalaSourceFile* value)
{
	BalaSourceFile* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_source_file_get_data (self);
	if (old_value != value) {
		BalaSourceFile* _tmp0_;
		_tmp0_ = _bala_source_file_ref0 (value);
		_bala_source_file_unref0 (self->priv->_data);
		self->priv->_data = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_DATA_PROPERTY]);
	}
}

BaladocApiSourceFile*
baladoc_api_source_file_construct (GType object_type,
                                   BaladocApiPackage* package,
                                   const gchar* relative_path,
                                   const gchar* relative_c_path,
                                   BalaSourceFile* data)
{
	BaladocApiSourceFile * self = NULL;
	g_return_val_if_fail (package != NULL, NULL);
	g_return_val_if_fail (relative_path != NULL, NULL);
	self = (BaladocApiSourceFile*) g_object_new (object_type, NULL);
	baladoc_api_source_file_set_relative_c_path (self, relative_c_path);
	baladoc_api_source_file_set_relative_path (self, relative_path);
	baladoc_api_source_file_set_package (self, package);
	baladoc_api_source_file_set_data (self, data);
	return self;
}

BaladocApiSourceFile*
baladoc_api_source_file_new (BaladocApiPackage* package,
                             const gchar* relative_path,
                             const gchar* relative_c_path,
                             BalaSourceFile* data)
{
	return baladoc_api_source_file_construct (BALADOC_API_TYPE_SOURCE_FILE, package, relative_path, relative_c_path, data);
}

static void
baladoc_api_source_file_class_init (BaladocApiSourceFileClass * klass,
                                    gpointer klass_data)
{
	baladoc_api_source_file_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &BaladocApiSourceFile_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_api_source_file_get_property;
	G_OBJECT_CLASS (klass)->set_property = _bala_baladoc_api_source_file_set_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_api_source_file_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SOURCE_FILE_PACKAGE_PROPERTY, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_PACKAGE_PROPERTY] = g_param_spec_object ("package", "package", "package", BALADOC_API_TYPE_PACKAGE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SOURCE_FILE_RELATIVE_PATH_PROPERTY, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_RELATIVE_PATH_PROPERTY] = g_param_spec_string ("relative-path", "relative-path", "relative-path", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SOURCE_FILE_RELATIVE_C_PATH_PROPERTY, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_RELATIVE_C_PATH_PROPERTY] = g_param_spec_string ("relative-c-path", "relative-c-path", "relative-c-path", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_SOURCE_FILE_DATA_PROPERTY, baladoc_api_source_file_properties[BALADOC_API_SOURCE_FILE_DATA_PROPERTY] = bala_param_spec_source_file ("data", "data", "data", BALA_TYPE_SOURCE_FILE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
baladoc_api_source_file_instance_init (BaladocApiSourceFile * self,
                                       gpointer klass)
{
	self->priv = baladoc_api_source_file_get_instance_private (self);
}

static void
baladoc_api_source_file_finalize (GObject * obj)
{
	BaladocApiSourceFile * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_SOURCE_FILE, BaladocApiSourceFile);
	_g_object_unref0 (self->priv->_package);
	_g_free0 (self->priv->_relative_path);
	_g_free0 (self->priv->_relative_c_path);
	_bala_source_file_unref0 (self->priv->_data);
	G_OBJECT_CLASS (baladoc_api_source_file_parent_class)->finalize (obj);
}

/**
 * Represents a source file
 */
static GType
baladoc_api_source_file_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocApiSourceFileClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_source_file_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocApiSourceFile), 0, (GInstanceInitFunc) baladoc_api_source_file_instance_init, NULL };
	GType baladoc_api_source_file_type_id;
	baladoc_api_source_file_type_id = g_type_register_static (G_TYPE_OBJECT, "BaladocApiSourceFile", &g_define_type_info, 0);
	BaladocApiSourceFile_private_offset = g_type_add_instance_private (baladoc_api_source_file_type_id, sizeof (BaladocApiSourceFilePrivate));
	return baladoc_api_source_file_type_id;
}

GType
baladoc_api_source_file_get_type (void)
{
	static volatile gsize baladoc_api_source_file_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_source_file_type_id__volatile)) {
		GType baladoc_api_source_file_type_id;
		baladoc_api_source_file_type_id = baladoc_api_source_file_get_type_once ();
		g_once_init_leave (&baladoc_api_source_file_type_id__volatile, baladoc_api_source_file_type_id);
	}
	return baladoc_api_source_file_type_id__volatile;
}

static void
_bala_baladoc_api_source_file_get_property (GObject * object,
                                            guint property_id,
                                            GValue * value,
                                            GParamSpec * pspec)
{
	BaladocApiSourceFile * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_SOURCE_FILE, BaladocApiSourceFile);
	switch (property_id) {
		case BALADOC_API_SOURCE_FILE_PACKAGE_PROPERTY:
		g_value_set_object (value, baladoc_api_source_file_get_package (self));
		break;
		case BALADOC_API_SOURCE_FILE_RELATIVE_PATH_PROPERTY:
		g_value_set_string (value, baladoc_api_source_file_get_relative_path (self));
		break;
		case BALADOC_API_SOURCE_FILE_RELATIVE_C_PATH_PROPERTY:
		g_value_set_string (value, baladoc_api_source_file_get_relative_c_path (self));
		break;
		case BALADOC_API_SOURCE_FILE_DATA_PROPERTY:
		bala_value_set_source_file (value, baladoc_api_source_file_get_data (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_bala_baladoc_api_source_file_set_property (GObject * object,
                                            guint property_id,
                                            const GValue * value,
                                            GParamSpec * pspec)
{
	BaladocApiSourceFile * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_SOURCE_FILE, BaladocApiSourceFile);
	switch (property_id) {
		case BALADOC_API_SOURCE_FILE_PACKAGE_PROPERTY:
		baladoc_api_source_file_set_package (self, g_value_get_object (value));
		break;
		case BALADOC_API_SOURCE_FILE_RELATIVE_PATH_PROPERTY:
		baladoc_api_source_file_set_relative_path (self, g_value_get_string (value));
		break;
		case BALADOC_API_SOURCE_FILE_RELATIVE_C_PATH_PROPERTY:
		baladoc_api_source_file_set_relative_c_path (self, g_value_get_string (value));
		break;
		case BALADOC_API_SOURCE_FILE_DATA_PROPERTY:
		baladoc_api_source_file_set_data (self, bala_value_get_source_file (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

