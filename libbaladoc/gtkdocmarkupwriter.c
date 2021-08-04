/* gtkdocmarkupwriter.c generated by balac, the Bala compiler
 * generated from gtkdocmarkupwriter.bala, do not modify */

/* gtkdocmarkupwriter.bala
 *
 * Copyright (C) 2012  Florian Brosch
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
#include <stdlib.h>
#include <string.h>

typedef struct _Block1Data Block1Data;
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
#define _baladoc_markup_writer_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_markup_writer_unref (var), NULL)))

struct _BaladocGtkDocMarkupWriterPrivate {
	GString* builder;
};

struct _Block1Data {
	int _ref_count_;
	BaladocGtkDocMarkupWriter* self;
	GString* builder;
};

static gint BaladocGtkDocMarkupWriter_private_offset;
static gpointer baladoc_gtk_doc_markup_writer_parent_class = NULL;

static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void __lambda131_ (Block1Data* _data1_,
                   const gchar* str);
static void ___lambda131__baladoc_markup_writer_write_func (const gchar* text,
                                                     gpointer self);
static gboolean baladoc_gtk_doc_markup_writer_real_inline_element (BaladocMarkupWriter* base,
                                                            const gchar* name);
static gboolean baladoc_gtk_doc_markup_writer_real_content_inline_element (BaladocMarkupWriter* base,
                                                                    const gchar* name);
static void baladoc_gtk_doc_markup_writer_finalize (BaladocMarkupWriter * obj);
static GType baladoc_gtk_doc_markup_writer_get_type_once (void);

static inline gpointer
baladoc_gtk_doc_markup_writer_get_instance_private (BaladocGtkDocMarkupWriter* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocGtkDocMarkupWriter_private_offset);
}

void
baladoc_gtk_doc_markup_writer_reset (BaladocGtkDocMarkupWriter* self)
{
	GString* _tmp0_;
	g_return_if_fail (self != NULL);
	((BaladocMarkupWriter*) self)->last_was_tag = TRUE;
	((BaladocMarkupWriter*) self)->current_column = (glong) 0;
	_tmp0_ = self->priv->builder;
	g_string_erase (_tmp0_, (gssize) 0, (gssize) -1);
	((BaladocMarkupWriter*) self)->indent = -1;
}

const gchar*
baladoc_gtk_doc_markup_writer_get_content (BaladocGtkDocMarkupWriter* self)
{
	const gchar* result;
	GString* _tmp0_;
	const gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->builder;
	_tmp1_ = _tmp0_->str;
	result = _tmp1_;
	return result;
}

static Block1Data*
block1_data_ref (Block1Data* _data1_)
{
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}

static void
block1_data_unref (void * _userdata_)
{
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		BaladocGtkDocMarkupWriter* self;
		self = _data1_->self;
		_g_string_free0 (_data1_->builder);
		_baladoc_markup_writer_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}

static void
__lambda131_ (Block1Data* _data1_,
              const gchar* str)
{
	BaladocGtkDocMarkupWriter* self;
	self = _data1_->self;
	g_return_if_fail (str != NULL);
	g_string_append (_data1_->builder, str);
}

static void
___lambda131__baladoc_markup_writer_write_func (const gchar* text,
                                                gpointer self)
{
	__lambda131_ (self, text);
}

BaladocGtkDocMarkupWriter*
baladoc_gtk_doc_markup_writer_construct (GType object_type)
{
	BaladocGtkDocMarkupWriter* self = NULL;
	Block1Data* _data1_;
	GString* _tmp0_;
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_tmp0_ = g_string_new ("");
	_data1_->builder = _tmp0_;
	self = (BaladocGtkDocMarkupWriter*) baladoc_markup_writer_construct (object_type, ___lambda131__baladoc_markup_writer_write_func, block1_data_ref (_data1_), block1_data_unref, FALSE);
	_data1_->self = baladoc_markup_writer_ref (self);
	self->priv->builder = _data1_->builder;
	block1_data_unref (_data1_);
	_data1_ = NULL;
	return self;
}

BaladocGtkDocMarkupWriter*
baladoc_gtk_doc_markup_writer_new (void)
{
	return baladoc_gtk_doc_markup_writer_construct (BALADOC_TYPE_GTK_DOC_MARKUP_WRITER);
}

static gboolean
baladoc_gtk_doc_markup_writer_real_inline_element (BaladocMarkupWriter* base,
                                                   const gchar* name)
{
	BaladocGtkDocMarkupWriter * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	gboolean _tmp8_ = FALSE;
	gboolean _tmp9_ = FALSE;
	gboolean _tmp10_ = FALSE;
	gboolean _tmp11_ = FALSE;
	gboolean _tmp12_ = FALSE;
	gboolean result = FALSE;
	self = (BaladocGtkDocMarkupWriter*) base;
	g_return_val_if_fail (name != NULL, FALSE);
	if (g_strcmp0 (name, "para") != 0) {
		_tmp12_ = g_strcmp0 (name, "programlisting") != 0;
	} else {
		_tmp12_ = FALSE;
	}
	if (_tmp12_) {
		_tmp11_ = g_strcmp0 (name, "table") != 0;
	} else {
		_tmp11_ = FALSE;
	}
	if (_tmp11_) {
		_tmp10_ = g_strcmp0 (name, "example") != 0;
	} else {
		_tmp10_ = FALSE;
	}
	if (_tmp10_) {
		_tmp9_ = g_strcmp0 (name, "figure") != 0;
	} else {
		_tmp9_ = FALSE;
	}
	if (_tmp9_) {
		_tmp8_ = g_strcmp0 (name, "tr") != 0;
	} else {
		_tmp8_ = FALSE;
	}
	if (_tmp8_) {
		_tmp7_ = g_strcmp0 (name, "td") != 0;
	} else {
		_tmp7_ = FALSE;
	}
	if (_tmp7_) {
		_tmp6_ = g_strcmp0 (name, "mediaobject") != 0;
	} else {
		_tmp6_ = FALSE;
	}
	if (_tmp6_) {
		_tmp5_ = g_strcmp0 (name, "imageobject") != 0;
	} else {
		_tmp5_ = FALSE;
	}
	if (_tmp5_) {
		_tmp4_ = g_strcmp0 (name, "textobject") != 0;
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		_tmp3_ = g_strcmp0 (name, "listitem") != 0;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		_tmp2_ = g_strcmp0 (name, "orderedlist") != 0;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		_tmp1_ = g_strcmp0 (name, "itemizedlist") != 0;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = g_strcmp0 (name, "title") != 0;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static gboolean
baladoc_gtk_doc_markup_writer_real_content_inline_element (BaladocMarkupWriter* base,
                                                           const gchar* name)
{
	BaladocGtkDocMarkupWriter * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp5_ = FALSE;
	gboolean result = FALSE;
	self = (BaladocGtkDocMarkupWriter*) base;
	g_return_val_if_fail (name != NULL, FALSE);
	if (g_strcmp0 (name, "para") == 0) {
		_tmp5_ = TRUE;
	} else {
		_tmp5_ = g_strcmp0 (name, "programlisting") == 0;
	}
	if (_tmp5_) {
		_tmp4_ = TRUE;
	} else {
		_tmp4_ = g_strcmp0 (name, "emphasis") == 0;
	}
	if (_tmp4_) {
		_tmp3_ = TRUE;
	} else {
		_tmp3_ = g_strcmp0 (name, "blockquote") == 0;
	}
	if (_tmp3_) {
		_tmp2_ = TRUE;
	} else {
		_tmp2_ = g_strcmp0 (name, "ulink") == 0;
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = g_strcmp0 (name, "listitem") == 0;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = g_strcmp0 (name, "title") == 0;
	}
	result = _tmp0_;
	return result;
}

static void
baladoc_gtk_doc_markup_writer_class_init (BaladocGtkDocMarkupWriterClass * klass,
                                          gpointer klass_data)
{
	baladoc_gtk_doc_markup_writer_parent_class = g_type_class_peek_parent (klass);
	((BaladocMarkupWriterClass *) klass)->finalize = baladoc_gtk_doc_markup_writer_finalize;
	g_type_class_adjust_private_offset (klass, &BaladocGtkDocMarkupWriter_private_offset);
	((BaladocMarkupWriterClass *) klass)->inline_element = (gboolean (*) (BaladocMarkupWriter*, const gchar*)) baladoc_gtk_doc_markup_writer_real_inline_element;
	((BaladocMarkupWriterClass *) klass)->content_inline_element = (gboolean (*) (BaladocMarkupWriter*, const gchar*)) baladoc_gtk_doc_markup_writer_real_content_inline_element;
}

static void
baladoc_gtk_doc_markup_writer_instance_init (BaladocGtkDocMarkupWriter * self,
                                             gpointer klass)
{
	self->priv = baladoc_gtk_doc_markup_writer_get_instance_private (self);
}

static void
baladoc_gtk_doc_markup_writer_finalize (BaladocMarkupWriter * obj)
{
	BaladocGtkDocMarkupWriter * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_TYPE_GTK_DOC_MARKUP_WRITER, BaladocGtkDocMarkupWriter);
	BALADOC_MARKUP_WRITER_CLASS (baladoc_gtk_doc_markup_writer_parent_class)->finalize (obj);
}

static GType
baladoc_gtk_doc_markup_writer_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocGtkDocMarkupWriterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_gtk_doc_markup_writer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocGtkDocMarkupWriter), 0, (GInstanceInitFunc) baladoc_gtk_doc_markup_writer_instance_init, NULL };
	GType baladoc_gtk_doc_markup_writer_type_id;
	baladoc_gtk_doc_markup_writer_type_id = g_type_register_static (BALADOC_TYPE_MARKUP_WRITER, "BaladocGtkDocMarkupWriter", &g_define_type_info, 0);
	BaladocGtkDocMarkupWriter_private_offset = g_type_add_instance_private (baladoc_gtk_doc_markup_writer_type_id, sizeof (BaladocGtkDocMarkupWriterPrivate));
	return baladoc_gtk_doc_markup_writer_type_id;
}

GType
baladoc_gtk_doc_markup_writer_get_type (void)
{
	static volatile gsize baladoc_gtk_doc_markup_writer_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_gtk_doc_markup_writer_type_id__volatile)) {
		GType baladoc_gtk_doc_markup_writer_type_id;
		baladoc_gtk_doc_markup_writer_type_id = baladoc_gtk_doc_markup_writer_get_type_once ();
		g_once_init_leave (&baladoc_gtk_doc_markup_writer_type_id__volatile, baladoc_gtk_doc_markup_writer_type_id);
	}
	return baladoc_gtk_doc_markup_writer_type_id__volatile;
}

