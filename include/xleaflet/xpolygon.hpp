/******************************************************************************
* Copyright (c) 2018, Sylvain Corlay and Johan Mabille, Wolf Vollprecht and   *
* Martin Renou                                                                *
*                                                                             *
* Distributed under the terms of the BSD 3-Clause License.                    *
*                                                                             *
* The full license is in the file LICENSE, distributed with this software.    *
*******************************************************************************/

#ifndef XLEAFLET_POLYGON_HPP
#define XLEAFLET_POLYGON_HPP

#include "xwidgets/xmaterialize.hpp"
#include "xwidgets/xwidget.hpp"

#include "xpolyline.hpp"

namespace xlf
{
    /***********************
     * polygon declaration *
     ***********************/

    template <class D>
    class xpolygon : public xpolyline<D>
    {
    public:

        using base_type = xpolyline<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

    protected:

        xpolygon();
        using base_type::base_type;

    private:

        void set_defaults();
    };

    using polygon = xw::xmaterialize<xpolygon>;

    using polygon_generator = xw::xgenerator<xpolygon>;

    /***************************
     * xpolygon implementation *
     ***************************/

    template <class D>
    inline void xpolygon<D>::serialize_state(xeus::xjson& state,
                                             xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);
    }

    template <class D>
    inline void xpolygon<D>::apply_patch(const xeus::xjson& patch,
                                         const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);
    }

    template <class D>
    inline xpolygon<D>::xpolygon()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpolygon<D>::set_defaults()
    {
        this->_model_name() = "LeafletPolygonModel";
        this->_view_name() = "LeafletPolygonView";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xlf::xpolygon>;
    extern template xw::xmaterialize<xlf::xpolygon>::xmaterialize();
    extern template class xw::xtransport<xw::xmaterialize<xlf::xpolygon>>;
    extern template class xw::xgenerator<xlf::xpolygon>;
    extern template xw::xgenerator<xlf::xpolygon>::xgenerator();
    extern template class xw::xtransport<xw::xgenerator<xlf::xpolygon>>;
#endif

#endif
