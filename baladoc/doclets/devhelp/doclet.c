/* doclet.c generated by balac, the Bala compiler
 * generated from doclet.bala, do not modify */

/* doclet.bala
 *
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
 * 	Florian Brosch <flo.brosch@gmail.com>
 */

#include <baladoc.h>
#include <glib-object.h>
#include <balagee.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <config.h>
#include <stdio.h>

#define BALADOC_DEVHELP_TYPE_DOCLET (baladoc_devhelp_doclet_get_type ())
#define BALADOC_DEVHELP_DOCLET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BALADOC_DEVHELP_TYPE_DOCLET, BaladocDevhelpDoclet))
#define BALADOC_DEVHELP_DOCLET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BALADOC_DEVHELP_TYPE_DOCLET, BaladocDevhelpDocletClass))
#define BALADOC_DEVHELP_IS_DOCLET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BALADOC_DEVHELP_TYPE_DOCLET))
#define BALADOC_DEVHELP_IS_DOCLET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BALADOC_DEVHELP_TYPE_DOCLET))
#define BALADOC_DEVHELP_DOCLET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BALADOC_DEVHELP_TYPE_DOCLET, BaladocDevhelpDocletClass))

typedef struct _BaladocDevhelpDoclet BaladocDevhelpDoclet;
typedef struct _BaladocDevhelpDocletClass BaladocDevhelpDocletClass;
typedef struct _BaladocDevhelpDocletPrivate BaladocDevhelpDocletPrivate;
enum  {
	BALADOC_DEVHELP_DOCLET_0_PROPERTY,
	BALADOC_DEVHELP_DOCLET_NUM_PROPERTIES
};
static GParamSpec* baladoc_devhelp_doclet_properties[BALADOC_DEVHELP_DOCLET_NUM_PROPERTIES];
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _baladoc_markup_writer_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_markup_writer_unref (var), NULL)))
#define _fclose0(var) ((var == NULL) ? NULL : (var = (fclose (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _BaladocDevhelpDoclet {
	BaladocHtmlBasicDoclet parent_instance;
	BaladocDevhelpDocletPrivate * priv;
};

struct _BaladocDevhelpDocletClass {
	BaladocHtmlBasicDocletClass parent_class;
};

struct _BaladocDevhelpDocletPrivate {
	BalaArrayList* nodes;
	gchar* package_dir_name;
	BaladocDevhelpMarkupWriter* _devhelpwriter;
};

static gint BaladocDevhelpDoclet_private_offset;
static gpointer baladoc_devhelp_doclet_parent_class = NULL;

GType baladoc_devhelp_doclet_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BaladocDevhelpDoclet, g_object_unref)
#define BALADOC_DEVHELP_DOCLET_css_path_wiki "devhelpstyle.css"
#define BALADOC_DEVHELP_DOCLET_css_path "devhelpstyle.css"
#define BALADOC_DEVHELP_DOCLET_js_path_wiki "scripts.js"
#define BALADOC_DEVHELP_DOCLET_js_path "scripts.js"
static gchar* baladoc_devhelp_doclet_get_path (BaladocDevhelpDoclet* self,
                                        BaladocApiNode* element);
static gchar* baladoc_devhelp_doclet_get_real_path (BaladocDevhelpDoclet* self,
                                             BaladocApiNode* element);
static gchar* baladoc_devhelp_doclet_real_get_icon_directory (BaladocHtmlBasicDoclet* base);
static void baladoc_devhelp_doclet_real_process (BaladocHtmlBasicDoclet* base,
                                          BaladocSettings* settings,
                                          BaladocApiTree* tree,
                                          BaladocErrorReporter* reporter);
static void baladoc_devhelp_doclet_real_visit_tree (BaladocApiVisitor* base,
                                             BaladocApiTree* tree);
static void baladoc_devhelp_doclet_real_visit_package (BaladocApiVisitor* base,
                                                BaladocApiPackage* package);
static void baladoc_devhelp_doclet_process_compound_node (BaladocDevhelpDoclet* self,
                                                   BaladocApiNode* node);
static void baladoc_devhelp_doclet_process_node (BaladocDevhelpDoclet* self,
                                          BaladocApiNode* node,
                                          gboolean accept_all_children);
static void baladoc_devhelp_doclet_real_visit_namespace (BaladocApiVisitor* base,
                                                  BaladocApiNamespace* item);
static void baladoc_devhelp_doclet_real_visit_interface (BaladocApiVisitor* base,
                                                  BaladocApiInterface* item);
static void baladoc_devhelp_doclet_real_visit_class (BaladocApiVisitor* base,
                                              BaladocApiClass* item);
static void baladoc_devhelp_doclet_real_visit_struct (BaladocApiVisitor* base,
                                               BaladocApiStruct* item);
static void baladoc_devhelp_doclet_real_visit_error_domain (BaladocApiVisitor* base,
                                                     BaladocApiErrorDomain* item);
static void baladoc_devhelp_doclet_real_visit_enum (BaladocApiVisitor* base,
                                             BaladocApiEnum* item);
static void baladoc_devhelp_doclet_real_visit_property (BaladocApiVisitor* base,
                                                 BaladocApiProperty* item);
static void baladoc_devhelp_doclet_real_visit_constant (BaladocApiVisitor* base,
                                                 BaladocApiConstant* item);
static void baladoc_devhelp_doclet_real_visit_field (BaladocApiVisitor* base,
                                              BaladocApiField* item);
static void baladoc_devhelp_doclet_real_visit_error_code (BaladocApiVisitor* base,
                                                   BaladocApiErrorCode* item);
static void baladoc_devhelp_doclet_real_visit_enum_value (BaladocApiVisitor* base,
                                                   BaladocApiEnumValue* item);
static void baladoc_devhelp_doclet_real_visit_delegate (BaladocApiVisitor* base,
                                                 BaladocApiDelegate* item);
static void baladoc_devhelp_doclet_real_visit_signal (BaladocApiVisitor* base,
                                               BaladocApiSignal* item);
static void baladoc_devhelp_doclet_real_visit_method (BaladocApiVisitor* base,
                                               BaladocApiMethod* item);
BaladocDevhelpDoclet* baladoc_devhelp_doclet_new (void);
BaladocDevhelpDoclet* baladoc_devhelp_doclet_construct (GType object_type);
static void baladoc_devhelp_doclet_finalize (GObject * obj);
static GType baladoc_devhelp_doclet_get_type_once (void);
GType register_plugin (BaladocModuleLoader* module_loader);
static void _bala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _bala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);

static inline gpointer
baladoc_devhelp_doclet_get_instance_private (BaladocDevhelpDoclet* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocDevhelpDoclet_private_offset);
}

static gchar*
baladoc_devhelp_doclet_get_path (BaladocDevhelpDoclet* self,
                                 BaladocApiNode* element)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (element != NULL, NULL);
	_tmp0_ = baladoc_api_node_get_full_name (element);
	_tmp1_ = _tmp0_;
	_tmp2_ = g_strconcat (_tmp1_, ".html", NULL);
	_tmp3_ = _tmp2_;
	_g_free0 (_tmp1_);
	result = _tmp3_;
	return result;
}

static gchar*
baladoc_devhelp_doclet_get_real_path (BaladocDevhelpDoclet* self,
                                      BaladocApiNode* element)
{
	BaladocSettings* _tmp0_;
	BaladocSettings* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (element != NULL, NULL);
	_tmp0_ = baladoc_html_basic_doclet_get_settings ((BaladocHtmlBasicDoclet*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_->path;
	_tmp3_ = self->priv->package_dir_name;
	_tmp4_ = baladoc_api_node_get_full_name (element);
	_tmp5_ = _tmp4_;
	_tmp6_ = g_strconcat (_tmp5_, ".html", NULL);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_build_filename (_tmp2_, _tmp3_, _tmp7_, NULL);
	_tmp9_ = _tmp8_;
	_g_free0 (_tmp7_);
	_g_free0 (_tmp5_);
	result = _tmp9_;
	return result;
}

static gchar*
baladoc_devhelp_doclet_real_get_icon_directory (BaladocHtmlBasicDoclet* base)
{
	BaladocDevhelpDoclet * self;
	gchar* _tmp0_;
	gchar* result = NULL;
	self = (BaladocDevhelpDoclet*) base;
	_tmp0_ = g_strdup ("");
	result = _tmp0_;
	return result;
}

static void
baladoc_devhelp_doclet_real_process (BaladocHtmlBasicDoclet* base,
                                     BaladocSettings* settings,
                                     BaladocApiTree* tree,
                                     BaladocErrorReporter* reporter)
{
	BaladocDevhelpDoclet * self;
	BaladocSettings* _tmp0_;
	BaladocSettings* _tmp1_;
	const gchar* _tmp2_;
	BaladocSettings* _tmp3_;
	BaladocSettings* _tmp4_;
	const gchar* _tmp5_;
	BaladocSettings* _tmp6_;
	BaladocSettings* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (settings != NULL);
	g_return_if_fail (tree != NULL);
	g_return_if_fail (reporter != NULL);
	BALADOC_HTML_BASIC_DOCLET_CLASS (baladoc_devhelp_doclet_parent_class)->process (G_TYPE_CHECK_INSTANCE_CAST (self, BALADOC_HTML_TYPE_BASIC_DOCLET, BaladocHtmlBasicDoclet), settings, tree, reporter);
	_tmp0_ = baladoc_html_basic_doclet_get_settings ((BaladocHtmlBasicDoclet*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_->path;
	g_mkdir_with_parents (_tmp2_, 0777);
	_tmp3_ = baladoc_html_basic_doclet_get_settings ((BaladocHtmlBasicDoclet*) self);
	_tmp4_ = _tmp3_;
	_tmp5_ = _tmp4_->path;
	_tmp6_ = baladoc_html_basic_doclet_get_settings ((BaladocHtmlBasicDoclet*) self);
	_tmp7_ = _tmp6_;
	_tmp8_ = _tmp7_->pkg_name;
	_tmp9_ = g_build_filename (_tmp5_, _tmp8_, NULL);
	_tmp10_ = _tmp9_;
	baladoc_html_basic_doclet_write_wiki_pages ((BaladocHtmlBasicDoclet*) self, tree, BALADOC_DEVHELP_DOCLET_css_path_wiki, BALADOC_DEVHELP_DOCLET_js_path_wiki, _tmp10_);
	_g_free0 (_tmp10_);
	baladoc_api_tree_accept (tree, (BaladocApiVisitor*) self);
}

static void
baladoc_devhelp_doclet_real_visit_tree (BaladocApiVisitor* base,
                                        BaladocApiTree* tree)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (tree != NULL);
	baladoc_api_tree_accept_children (tree, (BaladocApiVisitor*) self);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static void
baladoc_devhelp_doclet_real_visit_package (BaladocApiVisitor* base,
                                           BaladocApiPackage* package)
{
	BaladocDevhelpDoclet * self;
	BaladocSettings* _tmp0_;
	BaladocSettings* _tmp1_;
	gchar* pkg_name = NULL;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* path = NULL;
	BaladocSettings* _tmp5_;
	BaladocSettings* _tmp6_;
	const gchar* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* filepath = NULL;
	const gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* imgpath = NULL;
	const gchar* _tmp12_;
	gchar* _tmp13_;
	gchar* devpath = NULL;
	const gchar* _tmp14_;
	const gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	gchar* _tmp18_;
	gchar* _tmp19_;
	const gchar* _tmp20_;
	gchar* _tmp21_;
	gint rt = 0;
	const gchar* _tmp22_;
	const gchar* _tmp23_;
	const gchar* _tmp24_;
	FILE* devfile = NULL;
	const gchar* _tmp28_;
	FILE* _tmp29_;
	FILE* _tmp30_;
	BaladocDevhelpMarkupWriter* _tmp31_;
	BaladocDevhelpMarkupWriter* _tmp32_;
	const gchar* _tmp33_;
	gchar* _tmp34_;
	gchar* _tmp35_;
	const gchar* _tmp36_;
	FILE* file = NULL;
	const gchar* _tmp37_;
	FILE* _tmp38_;
	FILE* _tmp39_;
	BaladocHtmlMarkupWriter* _tmp40_;
	BaladocHtmlHtmlRenderer* _tmp41_;
	BaladocHtmlMarkupWriter* _tmp42_;
	const gchar* _tmp43_;
	BaladocDevhelpMarkupWriter* _tmp44_;
	BaladocDevhelpMarkupWriter* _tmp45_;
	BaladocDevhelpMarkupWriter* _tmp46_;
	BaladocDevhelpMarkupWriter* _tmp86_;
	BaladocDevhelpMarkupWriter* _tmp87_;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (package != NULL);
	_tmp0_ = baladoc_html_basic_doclet_get_settings ((BaladocHtmlBasicDoclet*) self);
	_tmp1_ = _tmp0_;
	if (!baladoc_api_node_is_browsable ((BaladocApiNode*) package, _tmp1_)) {
		return;
	}
	_tmp2_ = baladoc_api_node_get_name ((BaladocApiNode*) package);
	_tmp3_ = _tmp2_;
	_tmp4_ = g_strdup (_tmp3_);
	pkg_name = _tmp4_;
	_tmp5_ = baladoc_html_basic_doclet_get_settings ((BaladocHtmlBasicDoclet*) self);
	_tmp6_ = _tmp5_;
	_tmp7_ = _tmp6_->path;
	_tmp8_ = pkg_name;
	_tmp9_ = g_build_filename (_tmp7_, _tmp8_, NULL);
	path = _tmp9_;
	_tmp10_ = path;
	_tmp11_ = g_build_filename (_tmp10_, "index.htm", NULL);
	filepath = _tmp11_;
	_tmp12_ = path;
	_tmp13_ = g_build_filename (_tmp12_, "img", NULL);
	imgpath = _tmp13_;
	_tmp14_ = path;
	_tmp15_ = pkg_name;
	_tmp16_ = g_strconcat (_tmp15_, ".devhelp2", NULL);
	_tmp17_ = _tmp16_;
	_tmp18_ = g_build_filename (_tmp14_, _tmp17_, NULL);
	_tmp19_ = _tmp18_;
	_g_free0 (_tmp17_);
	devpath = _tmp19_;
	_tmp20_ = pkg_name;
	_tmp21_ = g_strdup (_tmp20_);
	_g_free0 (self->priv->package_dir_name);
	self->priv->package_dir_name = _tmp21_;
	_tmp22_ = path;
	rt = g_mkdir (_tmp22_, 0777);
	_tmp23_ = imgpath;
	rt = g_mkdir (_tmp23_, 0777);
	_tmp24_ = path;
	if (!baladoc_copy_directory (PACKAGE_BALADOC_ICONDIR, _tmp24_)) {
		BaladocErrorReporter* _tmp25_;
		gchar* _tmp26_;
		gchar* _tmp27_;
		_tmp25_ = ((BaladocHtmlBasicDoclet*) self)->reporter;
		_tmp26_ = g_strdup_printf ("Couldn't copy resources from `%s'", PACKAGE_BALADOC_ICONDIR);
		_tmp27_ = _tmp26_;
		baladoc_error_reporter_simple_warning (_tmp25_, "Devhelp", "%s", _tmp27_);
		_g_free0 (_tmp27_);
	}
	_tmp28_ = devpath;
	_tmp29_ = g_fopen (_tmp28_, "w");
	devfile = _tmp29_;
	_tmp30_ = devfile;
	_tmp31_ = baladoc_devhelp_markup_writer_new (_tmp30_, TRUE);
	_baladoc_markup_writer_unref0 (self->priv->_devhelpwriter);
	self->priv->_devhelpwriter = _tmp31_;
	_tmp32_ = self->priv->_devhelpwriter;
	_tmp33_ = pkg_name;
	_tmp34_ = g_strconcat (_tmp33_, " Reference Manual", NULL);
	_tmp35_ = _tmp34_;
	_tmp36_ = pkg_name;
	baladoc_devhelp_markup_writer_start_book (_tmp32_, _tmp35_, "bala", "index.htm", _tmp36_, "", "");
	_g_free0 (_tmp35_);
	_tmp37_ = filepath;
	_tmp38_ = g_fopen (_tmp37_, "w");
	file = _tmp38_;
	_tmp39_ = file;
	_tmp40_ = baladoc_html_markup_writer_new (_tmp39_, TRUE);
	_baladoc_markup_writer_unref0 (((BaladocHtmlBasicDoclet*) self)->writer);
	((BaladocHtmlBasicDoclet*) self)->writer = _tmp40_;
	_tmp41_ = ((BaladocHtmlBasicDoclet*) self)->_renderer;
	_tmp42_ = ((BaladocHtmlBasicDoclet*) self)->writer;
	baladoc_html_html_renderer_set_writer (_tmp41_, _tmp42_);
	_tmp43_ = pkg_name;
	baladoc_html_basic_doclet_write_file_header ((BaladocHtmlBasicDoclet*) self, BALADOC_DEVHELP_DOCLET_css_path, BALADOC_DEVHELP_DOCLET_js_path, _tmp43_);
	baladoc_html_basic_doclet_write_package_content ((BaladocHtmlBasicDoclet*) self, package, (BaladocApiNode*) package);
	baladoc_html_basic_doclet_write_file_footer ((BaladocHtmlBasicDoclet*) self);
	_fclose0 (file);
	file = NULL;
	_tmp44_ = self->priv->_devhelpwriter;
	baladoc_devhelp_markup_writer_start_chapters (_tmp44_);
	baladoc_api_node_accept_all_children ((BaladocApiNode*) package, (BaladocApiVisitor*) self, TRUE);
	_tmp45_ = self->priv->_devhelpwriter;
	baladoc_devhelp_markup_writer_end_chapters (_tmp45_);
	_tmp46_ = self->priv->_devhelpwriter;
	baladoc_devhelp_markup_writer_start_functions (_tmp46_);
	{
		BalaArrayList* _node_list = NULL;
		BalaArrayList* _tmp47_;
		BalaArrayList* _tmp48_;
		gint _node_size = 0;
		BalaArrayList* _tmp49_;
		gint _tmp50_;
		gint _tmp51_;
		gint _node_index = 0;
		_tmp47_ = self->priv->nodes;
		_tmp48_ = _bala_iterable_ref0 (_tmp47_);
		_node_list = _tmp48_;
		_tmp49_ = _node_list;
		_tmp50_ = bala_collection_get_size ((BalaCollection*) _tmp49_);
		_tmp51_ = _tmp50_;
		_node_size = _tmp51_;
		_node_index = -1;
		while (TRUE) {
			gint _tmp52_;
			gint _tmp53_;
			BaladocApiNode* node = NULL;
			BalaArrayList* _tmp54_;
			gpointer _tmp55_;
			gchar* typekeyword = NULL;
			gchar* _tmp56_;
			BaladocApiNode* _tmp57_;
			BaladocDevhelpMarkupWriter* _tmp71_;
			gchar* _tmp72_;
			const gchar* _tmp73_;
			gchar* _tmp74_;
			gchar* _tmp75_;
			BaladocApiNode* _tmp76_;
			gchar* _tmp77_;
			gchar* _tmp78_;
			BaladocApiNode* _tmp79_;
			BaladocApiNode* _tmp80_;
			BaladocApiPackage* _tmp81_;
			BaladocApiPackage* _tmp82_;
			gchar* _tmp83_;
			gchar** _tmp84_;
			gchar** _tmp85_;
			gint _tmp85__length1;
			_node_index = _node_index + 1;
			_tmp52_ = _node_index;
			_tmp53_ = _node_size;
			if (!(_tmp52_ < _tmp53_)) {
				break;
			}
			_tmp54_ = _node_list;
			_tmp55_ = bala_list_get ((BalaList*) _tmp54_, _node_index);
			node = (BaladocApiNode*) _tmp55_;
			_tmp56_ = g_strdup ("");
			typekeyword = _tmp56_;
			_tmp57_ = node;
			if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp57_, BALADOC_API_TYPE_ENUM)) {
				gchar* _tmp58_;
				_tmp58_ = g_strdup ("enum");
				_g_free0 (typekeyword);
				typekeyword = _tmp58_;
			} else {
				BaladocApiNode* _tmp59_;
				_tmp59_ = node;
				if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp59_, BALADOC_API_TYPE_CONSTANT)) {
					gchar* _tmp60_;
					_tmp60_ = g_strdup ("constant");
					_g_free0 (typekeyword);
					typekeyword = _tmp60_;
				} else {
					BaladocApiNode* _tmp61_;
					_tmp61_ = node;
					if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp61_, BALADOC_API_TYPE_METHOD)) {
						gchar* _tmp62_;
						_tmp62_ = g_strdup ("function");
						_g_free0 (typekeyword);
						typekeyword = _tmp62_;
					} else {
						BaladocApiNode* _tmp63_;
						_tmp63_ = node;
						if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp63_, BALADOC_API_TYPE_FIELD)) {
							gchar* _tmp64_;
							_tmp64_ = g_strdup ("variable");
							_g_free0 (typekeyword);
							typekeyword = _tmp64_;
						} else {
							BaladocApiNode* _tmp65_;
							_tmp65_ = node;
							if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp65_, BALADOC_API_TYPE_PROPERTY)) {
								gchar* _tmp66_;
								_tmp66_ = g_strdup ("property");
								_g_free0 (typekeyword);
								typekeyword = _tmp66_;
							} else {
								BaladocApiNode* _tmp67_;
								_tmp67_ = node;
								if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp67_, BALADOC_API_TYPE_SIGNAL)) {
									gchar* _tmp68_;
									_tmp68_ = g_strdup ("signal");
									_g_free0 (typekeyword);
									typekeyword = _tmp68_;
								} else {
									BaladocApiNode* _tmp69_;
									_tmp69_ = node;
									if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp69_, BALADOC_API_TYPE_STRUCT)) {
										gchar* _tmp70_;
										_tmp70_ = g_strdup ("struct");
										_g_free0 (typekeyword);
										typekeyword = _tmp70_;
									}
								}
							}
						}
					}
				}
			}
			_tmp71_ = self->priv->_devhelpwriter;
			_tmp72_ = g_strdup ("type");
			_tmp73_ = typekeyword;
			_tmp74_ = g_strdup (_tmp73_);
			_tmp75_ = g_strdup ("name");
			_tmp76_ = node;
			_tmp77_ = baladoc_api_node_get_full_name (_tmp76_);
			_tmp78_ = g_strdup ("link");
			_tmp79_ = node;
			_tmp80_ = node;
			_tmp81_ = baladoc_documentation_get_package ((BaladocDocumentation*) _tmp80_);
			_tmp82_ = _tmp81_;
			_tmp83_ = baladoc_html_basic_doclet_get_link ((BaladocHtmlBasicDoclet*) self, _tmp79_, (BaladocApiNode*) _tmp82_);
			_tmp84_ = g_new0 (gchar*, 6 + 1);
			_tmp84_[0] = _tmp72_;
			_tmp84_[1] = _tmp74_;
			_tmp84_[2] = _tmp75_;
			_tmp84_[3] = _tmp77_;
			_tmp84_[4] = _tmp78_;
			_tmp84_[5] = _tmp83_;
			_tmp85_ = _tmp84_;
			_tmp85__length1 = 6;
			baladoc_markup_writer_simple_tag ((BaladocMarkupWriter*) _tmp71_, "keyword", _tmp85_, (gint) 6);
			_tmp85_ = (_bala_array_free (_tmp85_, _tmp85__length1, (GDestroyNotify) g_free), NULL);
			_g_free0 (typekeyword);
			_g_object_unref0 (node);
		}
		_bala_iterable_unref0 (_node_list);
	}
	_tmp86_ = self->priv->_devhelpwriter;
	baladoc_devhelp_markup_writer_end_functions (_tmp86_);
	_tmp87_ = self->priv->_devhelpwriter;
	baladoc_devhelp_markup_writer_end_book (_tmp87_);
	_fclose0 (file);
	_fclose0 (devfile);
	_g_free0 (devpath);
	_g_free0 (imgpath);
	_g_free0 (filepath);
	_g_free0 (path);
	_g_free0 (pkg_name);
}

static void
baladoc_devhelp_doclet_process_compound_node (BaladocDevhelpDoclet* self,
                                              BaladocApiNode* node)
{
	gchar* rpath = NULL;
	gchar* _tmp0_;
	gchar* path = NULL;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp20_;
	const gchar* _tmp21_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (node != NULL);
	_tmp0_ = baladoc_devhelp_doclet_get_real_path (self, node);
	rpath = _tmp0_;
	_tmp1_ = baladoc_devhelp_doclet_get_path (self, node);
	path = _tmp1_;
	_tmp2_ = baladoc_api_node_get_name (node);
	_tmp3_ = _tmp2_;
	if (_tmp3_ != NULL) {
		FILE* file = NULL;
		const gchar* _tmp4_;
		FILE* _tmp5_;
		FILE* _tmp6_;
		BaladocHtmlMarkupWriter* _tmp7_;
		BaladocHtmlHtmlRenderer* _tmp8_;
		BaladocHtmlMarkupWriter* _tmp9_;
		gchar* _tmp10_;
		gchar* _tmp11_;
		gchar* _tmp12_;
		gchar* _tmp13_;
		BaladocApiPackage* _tmp14_;
		BaladocApiPackage* _tmp15_;
		const gchar* _tmp16_;
		const gchar* _tmp17_;
		gchar* _tmp18_;
		gchar* _tmp19_;
		_tmp4_ = rpath;
		_tmp5_ = g_fopen (_tmp4_, "w");
		file = _tmp5_;
		_tmp6_ = file;
		_tmp7_ = baladoc_html_markup_writer_new (_tmp6_, TRUE);
		_baladoc_markup_writer_unref0 (((BaladocHtmlBasicDoclet*) self)->writer);
		((BaladocHtmlBasicDoclet*) self)->writer = _tmp7_;
		_tmp8_ = ((BaladocHtmlBasicDoclet*) self)->_renderer;
		_tmp9_ = ((BaladocHtmlBasicDoclet*) self)->writer;
		baladoc_html_html_renderer_set_writer (_tmp8_, _tmp9_);
		_tmp10_ = baladoc_api_node_get_full_name (node);
		_tmp11_ = _tmp10_;
		_tmp12_ = g_strconcat (_tmp11_, " &ndash; ", NULL);
		_tmp13_ = _tmp12_;
		_tmp14_ = baladoc_documentation_get_package ((BaladocDocumentation*) node);
		_tmp15_ = _tmp14_;
		_tmp16_ = baladoc_api_node_get_name ((BaladocApiNode*) _tmp15_);
		_tmp17_ = _tmp16_;
		_tmp18_ = g_strconcat (_tmp13_, _tmp17_, NULL);
		_tmp19_ = _tmp18_;
		baladoc_html_basic_doclet_write_file_header ((BaladocHtmlBasicDoclet*) self, BALADOC_DEVHELP_DOCLET_css_path, BALADOC_DEVHELP_DOCLET_js_path, _tmp19_);
		_g_free0 (_tmp19_);
		_g_free0 (_tmp13_);
		_g_free0 (_tmp11_);
		baladoc_html_basic_doclet_write_symbol_content ((BaladocHtmlBasicDoclet*) self, node);
		baladoc_html_basic_doclet_write_file_footer ((BaladocHtmlBasicDoclet*) self);
		_fclose0 (file);
		file = NULL;
		_fclose0 (file);
	}
	_tmp20_ = baladoc_api_node_get_name (node);
	_tmp21_ = _tmp20_;
	if (_tmp21_ != NULL) {
		BaladocDevhelpMarkupWriter* _tmp22_;
		const gchar* _tmp23_;
		const gchar* _tmp24_;
		const gchar* _tmp25_;
		BaladocDevhelpMarkupWriter* _tmp26_;
		BalaArrayList* _tmp27_;
		_tmp22_ = self->priv->_devhelpwriter;
		_tmp23_ = baladoc_api_node_get_name (node);
		_tmp24_ = _tmp23_;
		_tmp25_ = path;
		baladoc_devhelp_markup_writer_start_sub (_tmp22_, _tmp24_, _tmp25_);
		baladoc_api_node_accept_all_children (node, (BaladocApiVisitor*) self, TRUE);
		_tmp26_ = self->priv->_devhelpwriter;
		baladoc_devhelp_markup_writer_end_sub (_tmp26_);
		_tmp27_ = self->priv->nodes;
		bala_collection_add ((BalaCollection*) _tmp27_, node);
	} else {
		baladoc_api_node_accept_all_children (node, (BaladocApiVisitor*) self, TRUE);
	}
	_g_free0 (path);
	_g_free0 (rpath);
}

static void
baladoc_devhelp_doclet_process_node (BaladocDevhelpDoclet* self,
                                     BaladocApiNode* node,
                                     gboolean accept_all_children)
{
	gchar* rpath = NULL;
	gchar* _tmp0_;
	gchar* path = NULL;
	gchar* _tmp1_;
	FILE* file = NULL;
	const gchar* _tmp2_;
	FILE* _tmp3_;
	FILE* _tmp4_;
	BaladocHtmlMarkupWriter* _tmp5_;
	BaladocHtmlHtmlRenderer* _tmp6_;
	BaladocHtmlMarkupWriter* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	BaladocApiPackage* _tmp12_;
	BaladocApiPackage* _tmp13_;
	const gchar* _tmp14_;
	const gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	BalaArrayList* _tmp23_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (node != NULL);
	_tmp0_ = baladoc_devhelp_doclet_get_real_path (self, node);
	rpath = _tmp0_;
	_tmp1_ = baladoc_devhelp_doclet_get_path (self, node);
	path = _tmp1_;
	_tmp2_ = rpath;
	_tmp3_ = g_fopen (_tmp2_, "w");
	file = _tmp3_;
	_tmp4_ = file;
	_tmp5_ = baladoc_html_markup_writer_new (_tmp4_, TRUE);
	_baladoc_markup_writer_unref0 (((BaladocHtmlBasicDoclet*) self)->writer);
	((BaladocHtmlBasicDoclet*) self)->writer = _tmp5_;
	_tmp6_ = ((BaladocHtmlBasicDoclet*) self)->_renderer;
	_tmp7_ = ((BaladocHtmlBasicDoclet*) self)->writer;
	baladoc_html_html_renderer_set_writer (_tmp6_, _tmp7_);
	_tmp8_ = baladoc_api_node_get_full_name (node);
	_tmp9_ = _tmp8_;
	_tmp10_ = g_strconcat (_tmp9_, " &ndash; ", NULL);
	_tmp11_ = _tmp10_;
	_tmp12_ = baladoc_documentation_get_package ((BaladocDocumentation*) node);
	_tmp13_ = _tmp12_;
	_tmp14_ = baladoc_api_node_get_name ((BaladocApiNode*) _tmp13_);
	_tmp15_ = _tmp14_;
	_tmp16_ = g_strconcat (_tmp11_, _tmp15_, NULL);
	_tmp17_ = _tmp16_;
	baladoc_html_basic_doclet_write_file_header ((BaladocHtmlBasicDoclet*) self, BALADOC_DEVHELP_DOCLET_css_path, BALADOC_DEVHELP_DOCLET_js_path, _tmp17_);
	_g_free0 (_tmp17_);
	_g_free0 (_tmp11_);
	_g_free0 (_tmp9_);
	baladoc_html_basic_doclet_write_symbol_content ((BaladocHtmlBasicDoclet*) self, node);
	baladoc_html_basic_doclet_write_file_footer ((BaladocHtmlBasicDoclet*) self);
	_fclose0 (file);
	file = NULL;
	if (accept_all_children) {
		BaladocDevhelpMarkupWriter* _tmp18_;
		const gchar* _tmp19_;
		const gchar* _tmp20_;
		const gchar* _tmp21_;
		BaladocDevhelpMarkupWriter* _tmp22_;
		_tmp18_ = self->priv->_devhelpwriter;
		_tmp19_ = baladoc_api_node_get_name (node);
		_tmp20_ = _tmp19_;
		_tmp21_ = path;
		baladoc_devhelp_markup_writer_start_sub (_tmp18_, _tmp20_, _tmp21_);
		baladoc_api_node_accept_all_children (node, (BaladocApiVisitor*) self, TRUE);
		_tmp22_ = self->priv->_devhelpwriter;
		baladoc_devhelp_markup_writer_end_sub (_tmp22_);
	}
	_tmp23_ = self->priv->nodes;
	bala_collection_add ((BalaCollection*) _tmp23_, node);
	_fclose0 (file);
	_g_free0 (path);
	_g_free0 (rpath);
}

static void
baladoc_devhelp_doclet_real_visit_namespace (BaladocApiVisitor* base,
                                             BaladocApiNamespace* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_compound_node (self, (BaladocApiNode*) item);
}

static void
baladoc_devhelp_doclet_real_visit_interface (BaladocApiVisitor* base,
                                             BaladocApiInterface* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_compound_node (self, (BaladocApiNode*) item);
}

static void
baladoc_devhelp_doclet_real_visit_class (BaladocApiVisitor* base,
                                         BaladocApiClass* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_compound_node (self, (BaladocApiNode*) item);
}

static void
baladoc_devhelp_doclet_real_visit_struct (BaladocApiVisitor* base,
                                          BaladocApiStruct* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_compound_node (self, (BaladocApiNode*) item);
}

static void
baladoc_devhelp_doclet_real_visit_error_domain (BaladocApiVisitor* base,
                                                BaladocApiErrorDomain* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, TRUE);
}

static void
baladoc_devhelp_doclet_real_visit_enum (BaladocApiVisitor* base,
                                        BaladocApiEnum* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, TRUE);
}

static void
baladoc_devhelp_doclet_real_visit_property (BaladocApiVisitor* base,
                                            BaladocApiProperty* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

static void
baladoc_devhelp_doclet_real_visit_constant (BaladocApiVisitor* base,
                                            BaladocApiConstant* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

static void
baladoc_devhelp_doclet_real_visit_field (BaladocApiVisitor* base,
                                         BaladocApiField* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

static void
baladoc_devhelp_doclet_real_visit_error_code (BaladocApiVisitor* base,
                                              BaladocApiErrorCode* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

static void
baladoc_devhelp_doclet_real_visit_enum_value (BaladocApiVisitor* base,
                                              BaladocApiEnumValue* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

static void
baladoc_devhelp_doclet_real_visit_delegate (BaladocApiVisitor* base,
                                            BaladocApiDelegate* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

static void
baladoc_devhelp_doclet_real_visit_signal (BaladocApiVisitor* base,
                                          BaladocApiSignal* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

static void
baladoc_devhelp_doclet_real_visit_method (BaladocApiVisitor* base,
                                          BaladocApiMethod* item)
{
	BaladocDevhelpDoclet * self;
	self = (BaladocDevhelpDoclet*) base;
	g_return_if_fail (item != NULL);
	baladoc_devhelp_doclet_process_node (self, (BaladocApiNode*) item, FALSE);
}

BaladocDevhelpDoclet*
baladoc_devhelp_doclet_construct (GType object_type)
{
	BaladocDevhelpDoclet * self = NULL;
	self = (BaladocDevhelpDoclet*) baladoc_html_basic_doclet_construct (object_type);
	return self;
}

BaladocDevhelpDoclet*
baladoc_devhelp_doclet_new (void)
{
	return baladoc_devhelp_doclet_construct (BALADOC_DEVHELP_TYPE_DOCLET);
}

static void
baladoc_devhelp_doclet_class_init (BaladocDevhelpDocletClass * klass,
                                   gpointer klass_data)
{
	baladoc_devhelp_doclet_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &BaladocDevhelpDoclet_private_offset);
	((BaladocHtmlBasicDocletClass *) klass)->get_icon_directory = (gchar* (*) (BaladocHtmlBasicDoclet*)) baladoc_devhelp_doclet_real_get_icon_directory;
	((BaladocHtmlBasicDocletClass *) klass)->process = (void (*) (BaladocHtmlBasicDoclet*, BaladocSettings*, BaladocApiTree*, BaladocErrorReporter*)) baladoc_devhelp_doclet_real_process;
	((BaladocApiVisitorClass *) klass)->visit_tree = (void (*) (BaladocApiVisitor*, BaladocApiTree*)) baladoc_devhelp_doclet_real_visit_tree;
	((BaladocApiVisitorClass *) klass)->visit_package = (void (*) (BaladocApiVisitor*, BaladocApiPackage*)) baladoc_devhelp_doclet_real_visit_package;
	((BaladocApiVisitorClass *) klass)->visit_namespace = (void (*) (BaladocApiVisitor*, BaladocApiNamespace*)) baladoc_devhelp_doclet_real_visit_namespace;
	((BaladocApiVisitorClass *) klass)->visit_interface = (void (*) (BaladocApiVisitor*, BaladocApiInterface*)) baladoc_devhelp_doclet_real_visit_interface;
	((BaladocApiVisitorClass *) klass)->visit_class = (void (*) (BaladocApiVisitor*, BaladocApiClass*)) baladoc_devhelp_doclet_real_visit_class;
	((BaladocApiVisitorClass *) klass)->visit_struct = (void (*) (BaladocApiVisitor*, BaladocApiStruct*)) baladoc_devhelp_doclet_real_visit_struct;
	((BaladocApiVisitorClass *) klass)->visit_error_domain = (void (*) (BaladocApiVisitor*, BaladocApiErrorDomain*)) baladoc_devhelp_doclet_real_visit_error_domain;
	((BaladocApiVisitorClass *) klass)->visit_enum = (void (*) (BaladocApiVisitor*, BaladocApiEnum*)) baladoc_devhelp_doclet_real_visit_enum;
	((BaladocApiVisitorClass *) klass)->visit_property = (void (*) (BaladocApiVisitor*, BaladocApiProperty*)) baladoc_devhelp_doclet_real_visit_property;
	((BaladocApiVisitorClass *) klass)->visit_constant = (void (*) (BaladocApiVisitor*, BaladocApiConstant*)) baladoc_devhelp_doclet_real_visit_constant;
	((BaladocApiVisitorClass *) klass)->visit_field = (void (*) (BaladocApiVisitor*, BaladocApiField*)) baladoc_devhelp_doclet_real_visit_field;
	((BaladocApiVisitorClass *) klass)->visit_error_code = (void (*) (BaladocApiVisitor*, BaladocApiErrorCode*)) baladoc_devhelp_doclet_real_visit_error_code;
	((BaladocApiVisitorClass *) klass)->visit_enum_value = (void (*) (BaladocApiVisitor*, BaladocApiEnumValue*)) baladoc_devhelp_doclet_real_visit_enum_value;
	((BaladocApiVisitorClass *) klass)->visit_delegate = (void (*) (BaladocApiVisitor*, BaladocApiDelegate*)) baladoc_devhelp_doclet_real_visit_delegate;
	((BaladocApiVisitorClass *) klass)->visit_signal = (void (*) (BaladocApiVisitor*, BaladocApiSignal*)) baladoc_devhelp_doclet_real_visit_signal;
	((BaladocApiVisitorClass *) klass)->visit_method = (void (*) (BaladocApiVisitor*, BaladocApiMethod*)) baladoc_devhelp_doclet_real_visit_method;
	G_OBJECT_CLASS (klass)->finalize = baladoc_devhelp_doclet_finalize;
}

static void
baladoc_devhelp_doclet_instance_init (BaladocDevhelpDoclet * self,
                                      gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	gchar* _tmp2_;
	self->priv = baladoc_devhelp_doclet_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALADOC_API_TYPE_NODE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp0_);
	self->priv->nodes = _tmp1_;
	_tmp2_ = g_strdup ("");
	self->priv->package_dir_name = _tmp2_;
}

static void
baladoc_devhelp_doclet_finalize (GObject * obj)
{
	BaladocDevhelpDoclet * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_DEVHELP_TYPE_DOCLET, BaladocDevhelpDoclet);
	_bala_iterable_unref0 (self->priv->nodes);
	_g_free0 (self->priv->package_dir_name);
	_baladoc_markup_writer_unref0 (self->priv->_devhelpwriter);
	G_OBJECT_CLASS (baladoc_devhelp_doclet_parent_class)->finalize (obj);
}

static GType
baladoc_devhelp_doclet_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocDevhelpDocletClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_devhelp_doclet_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocDevhelpDoclet), 0, (GInstanceInitFunc) baladoc_devhelp_doclet_instance_init, NULL };
	GType baladoc_devhelp_doclet_type_id;
	baladoc_devhelp_doclet_type_id = g_type_register_static (BALADOC_HTML_TYPE_BASIC_DOCLET, "BaladocDevhelpDoclet", &g_define_type_info, 0);
	BaladocDevhelpDoclet_private_offset = g_type_add_instance_private (baladoc_devhelp_doclet_type_id, sizeof (BaladocDevhelpDocletPrivate));
	return baladoc_devhelp_doclet_type_id;
}

GType
baladoc_devhelp_doclet_get_type (void)
{
	static volatile gsize baladoc_devhelp_doclet_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_devhelp_doclet_type_id__volatile)) {
		GType baladoc_devhelp_doclet_type_id;
		baladoc_devhelp_doclet_type_id = baladoc_devhelp_doclet_get_type_once ();
		g_once_init_leave (&baladoc_devhelp_doclet_type_id__volatile, baladoc_devhelp_doclet_type_id);
	}
	return baladoc_devhelp_doclet_type_id__volatile;
}

GType
register_plugin (BaladocModuleLoader* module_loader)
{
	GType result = 0UL;
	g_return_val_if_fail (module_loader != NULL, 0UL);
	result = BALADOC_DEVHELP_TYPE_DOCLET;
	return result;
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

