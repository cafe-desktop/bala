/* chartfactory.c generated by valac, the Vala compiler
 * generated from chartfactory.vala, do not modify */

/* chartfactory.vala
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

#include <graphviz/gvc.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "valadoc.h"
#include <glib-object.h>

enum  {
	VALADOC_CHARTS_FACTORY_0_PROPERTY,
	VALADOC_CHARTS_FACTORY_NUM_PROPERTIES
};
static GParamSpec* valadoc_charts_factory_properties[VALADOC_CHARTS_FACTORY_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))

static gpointer valadoc_charts_factory_parent_class = NULL;

Agnode_t* valadoc_compat_gvc_graph_create_node (Agraph_t* graph,
                                                const gchar* name);
static Agraph_t* valadoc_charts_factory_real_create_graph (ValadocChartsFactory* self,
                                                    ValadocApiNode* item);
static GVC_t* valadoc_charts_factory_real_create_context (ValadocChartsFactory* self,
                                                   Agraph_t* graph);
static Agnode_t* valadoc_charts_factory_real_create_class (ValadocChartsFactory* self,
                                                    Agraph_t* graph,
                                                    ValadocApiClass* item);
static Agnode_t* valadoc_charts_factory_real_create_struct (ValadocChartsFactory* self,
                                                     Agraph_t* graph,
                                                     ValadocApiStruct* item);
static Agnode_t* valadoc_charts_factory_real_create_interface (ValadocChartsFactory* self,
                                                        Agraph_t* graph,
                                                        ValadocApiInterface* item);
static Agnode_t* valadoc_charts_factory_real_create_enum (ValadocChartsFactory* self,
                                                   Agraph_t* graph,
                                                   ValadocApiEnum* item);
static Agnode_t* valadoc_charts_factory_real_create_delegate (ValadocChartsFactory* self,
                                                       Agraph_t* graph,
                                                       ValadocApiDelegate* item);
static Agnode_t* valadoc_charts_factory_real_create_errordomain (ValadocChartsFactory* self,
                                                          Agraph_t* graph,
                                                          ValadocApiErrorDomain* item);
static Agnode_t* valadoc_charts_factory_real_create_namespace (ValadocChartsFactory* self,
                                                        Agraph_t* graph,
                                                        ValadocApiNamespace* item);
static Agedge_t* valadoc_charts_factory_real_add_children (ValadocChartsFactory* self,
                                                    Agraph_t* graph,
                                                    Agnode_t* parent,
                                                    Agnode_t* child);
static GType valadoc_charts_factory_get_type_once (void);

Agnode_t*
valadoc_charts_factory_create_type (ValadocChartsFactory* self,
                                    Agraph_t* graph,
                                    ValadocApiNode* item)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	Agnode_t* _tmp2_;
	Agnode_t* _tmp3_;
	Agnode_t* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (graph != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	_tmp0_ = valadoc_api_node_get_full_name (item);
	_tmp1_ = _tmp0_;
	_tmp2_ = valadoc_compat_gvc_graph_create_node (graph, _tmp1_);
	_tmp3_ = _tmp2_;
	_g_free0 (_tmp1_);
	result = _tmp3_;
	return result;
}

static Agraph_t*
valadoc_charts_factory_real_create_graph (ValadocChartsFactory* self,
                                          ValadocApiNode* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_graph'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agraph_t*
valadoc_charts_factory_create_graph (ValadocChartsFactory* self,
                                     ValadocApiNode* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_graph (self, item);
}

static GVC_t*
valadoc_charts_factory_real_create_context (ValadocChartsFactory* self,
                                            Agraph_t* graph)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_context'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

GVC_t*
valadoc_charts_factory_create_context (ValadocChartsFactory* self,
                                       Agraph_t* graph)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_context (self, graph);
}

static Agnode_t*
valadoc_charts_factory_real_create_class (ValadocChartsFactory* self,
                                          Agraph_t* graph,
                                          ValadocApiClass* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_class'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
valadoc_charts_factory_create_class (ValadocChartsFactory* self,
                                     Agraph_t* graph,
                                     ValadocApiClass* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_class (self, graph, item);
}

static Agnode_t*
valadoc_charts_factory_real_create_struct (ValadocChartsFactory* self,
                                           Agraph_t* graph,
                                           ValadocApiStruct* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_struct'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
valadoc_charts_factory_create_struct (ValadocChartsFactory* self,
                                      Agraph_t* graph,
                                      ValadocApiStruct* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_struct (self, graph, item);
}

static Agnode_t*
valadoc_charts_factory_real_create_interface (ValadocChartsFactory* self,
                                              Agraph_t* graph,
                                              ValadocApiInterface* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_interface'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
valadoc_charts_factory_create_interface (ValadocChartsFactory* self,
                                         Agraph_t* graph,
                                         ValadocApiInterface* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_interface (self, graph, item);
}

static Agnode_t*
valadoc_charts_factory_real_create_enum (ValadocChartsFactory* self,
                                         Agraph_t* graph,
                                         ValadocApiEnum* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_enum'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
valadoc_charts_factory_create_enum (ValadocChartsFactory* self,
                                    Agraph_t* graph,
                                    ValadocApiEnum* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_enum (self, graph, item);
}

static Agnode_t*
valadoc_charts_factory_real_create_delegate (ValadocChartsFactory* self,
                                             Agraph_t* graph,
                                             ValadocApiDelegate* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_delegate'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
valadoc_charts_factory_create_delegate (ValadocChartsFactory* self,
                                        Agraph_t* graph,
                                        ValadocApiDelegate* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_delegate (self, graph, item);
}

static Agnode_t*
valadoc_charts_factory_real_create_errordomain (ValadocChartsFactory* self,
                                                Agraph_t* graph,
                                                ValadocApiErrorDomain* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_errordomain'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
valadoc_charts_factory_create_errordomain (ValadocChartsFactory* self,
                                           Agraph_t* graph,
                                           ValadocApiErrorDomain* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_errordomain (self, graph, item);
}

static Agnode_t*
valadoc_charts_factory_real_create_namespace (ValadocChartsFactory* self,
                                              Agraph_t* graph,
                                              ValadocApiNamespace* item)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_create_namespace'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
valadoc_charts_factory_create_namespace (ValadocChartsFactory* self,
                                         Agraph_t* graph,
                                         ValadocApiNamespace* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_namespace (self, graph, item);
}

static Agedge_t*
valadoc_charts_factory_real_add_children (ValadocChartsFactory* self,
                                          Agraph_t* graph,
                                          Agnode_t* parent,
                                          Agnode_t* child)
{
	g_critical ("Type `%s' does not implement abstract method `valadoc_charts_factory_add_children'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agedge_t*
valadoc_charts_factory_add_children (ValadocChartsFactory* self,
                                     Agraph_t* graph,
                                     Agnode_t* parent,
                                     Agnode_t* child)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_CHARTS_FACTORY_GET_CLASS (self)->add_children (self, graph, parent, child);
}

ValadocChartsFactory*
valadoc_charts_factory_construct (GType object_type)
{
	ValadocChartsFactory * self = NULL;
	self = (ValadocChartsFactory*) g_object_new (object_type, NULL);
	return self;
}

static void
valadoc_charts_factory_class_init (ValadocChartsFactoryClass * klass,
                                   gpointer klass_data)
{
	valadoc_charts_factory_parent_class = g_type_class_peek_parent (klass);
	((ValadocChartsFactoryClass *) klass)->create_graph = (Agraph_t* (*) (ValadocChartsFactory*, ValadocApiNode*)) valadoc_charts_factory_real_create_graph;
	((ValadocChartsFactoryClass *) klass)->create_context = (GVC_t* (*) (ValadocChartsFactory*, Agraph_t*)) valadoc_charts_factory_real_create_context;
	((ValadocChartsFactoryClass *) klass)->create_class = (Agnode_t* (*) (ValadocChartsFactory*, Agraph_t*, ValadocApiClass*)) valadoc_charts_factory_real_create_class;
	((ValadocChartsFactoryClass *) klass)->create_struct = (Agnode_t* (*) (ValadocChartsFactory*, Agraph_t*, ValadocApiStruct*)) valadoc_charts_factory_real_create_struct;
	((ValadocChartsFactoryClass *) klass)->create_interface = (Agnode_t* (*) (ValadocChartsFactory*, Agraph_t*, ValadocApiInterface*)) valadoc_charts_factory_real_create_interface;
	((ValadocChartsFactoryClass *) klass)->create_enum = (Agnode_t* (*) (ValadocChartsFactory*, Agraph_t*, ValadocApiEnum*)) valadoc_charts_factory_real_create_enum;
	((ValadocChartsFactoryClass *) klass)->create_delegate = (Agnode_t* (*) (ValadocChartsFactory*, Agraph_t*, ValadocApiDelegate*)) valadoc_charts_factory_real_create_delegate;
	((ValadocChartsFactoryClass *) klass)->create_errordomain = (Agnode_t* (*) (ValadocChartsFactory*, Agraph_t*, ValadocApiErrorDomain*)) valadoc_charts_factory_real_create_errordomain;
	((ValadocChartsFactoryClass *) klass)->create_namespace = (Agnode_t* (*) (ValadocChartsFactory*, Agraph_t*, ValadocApiNamespace*)) valadoc_charts_factory_real_create_namespace;
	((ValadocChartsFactoryClass *) klass)->add_children = (Agedge_t* (*) (ValadocChartsFactory*, Agraph_t*, Agnode_t*, Agnode_t*)) valadoc_charts_factory_real_add_children;
}

static void
valadoc_charts_factory_instance_init (ValadocChartsFactory * self,
                                      gpointer klass)
{
}

static GType
valadoc_charts_factory_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocChartsFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_charts_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocChartsFactory), 0, (GInstanceInitFunc) valadoc_charts_factory_instance_init, NULL };
	GType valadoc_charts_factory_type_id;
	valadoc_charts_factory_type_id = g_type_register_static (G_TYPE_OBJECT, "ValadocChartsFactory", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return valadoc_charts_factory_type_id;
}

GType
valadoc_charts_factory_get_type (void)
{
	static volatile gsize valadoc_charts_factory_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_charts_factory_type_id__volatile)) {
		GType valadoc_charts_factory_type_id;
		valadoc_charts_factory_type_id = valadoc_charts_factory_get_type_once ();
		g_once_init_leave (&valadoc_charts_factory_type_id__volatile, valadoc_charts_factory_type_id);
	}
	return valadoc_charts_factory_type_id__volatile;
}
