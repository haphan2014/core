/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_SOURCE_UI_INC_FOPTMGR_HXX
#define INCLUDED_SC_SOURCE_UI_INC_FOPTMGR_HXX

#include <vcl/fixed.hxx>
#include <vcl/lstbox.hxx>
#include <vcl/button.hxx>

namespace formula
{
    class RefButton;
    class WeldRefButton;
    class WeldRefEdit;
}
struct ScQueryParam;
class ScDocument;
class ScViewData;

class ScFilterOptionsMgr
{
public:
    ScFilterOptionsMgr( ScViewData*         ptrViewData,
                        const ScQueryParam& refQueryData,
                        CheckBox*           refBtnCase,
                        CheckBox*           refBtnRegExp,
                        CheckBox*           refBtnHeader,
                        CheckBox*           refBtnUnique,
                        CheckBox*           refBtnCopyResult,
                        CheckBox*           refBtnDestPers,
                        ListBox*            refLbCopyArea,
                        Edit*               refEdCopyArea,
                        formula::RefButton* refRbCopyArea,
                        FixedText*          refFtDbAreaLabel,
                        FixedText*          refFtDbArea,
                        const OUString&       refStrUndefined );
    ~ScFilterOptionsMgr();
    bool    VerifyPosStr ( const OUString& rPosStr ) const;

private:
    ScViewData* const     pViewData;
    ScDocument* const     pDoc;

    VclPtr<CheckBox>       pBtnCase;
    VclPtr<CheckBox>       pBtnRegExp;
    VclPtr<CheckBox>       pBtnHeader;
    VclPtr<CheckBox>       pBtnUnique;
    VclPtr<CheckBox>       pBtnCopyResult;
    VclPtr<CheckBox>       pBtnDestPers;
    VclPtr<ListBox>        pLbCopyArea;
    VclPtr<Edit>           pEdCopyArea;
    VclPtr<formula::RefButton> pRbCopyArea;
    VclPtr<FixedText>      pFtDbAreaLabel;
    VclPtr<FixedText>      pFtDbArea;

    const OUString&   rStrUndefined;

    const ScQueryParam& rQueryData;

private:
    void Init();

    // Handler:
    DECL_LINK( EdAreaModifyHdl,     Edit&, void );
    DECL_LINK( LbAreaSelHdl,        ListBox&, void );
    DECL_LINK( BtnCopyResultHdl,    CheckBox&, void );
};

class FilterOptionsMgr
{
public:
    FilterOptionsMgr(ScViewData* ptrViewData,
                     const ScQueryParam& refQueryData,
                     weld::CheckButton*  refBtnCase,
                     weld::CheckButton* refBtnRegExp,
                     weld::CheckButton* refBtnHeader,
                     weld::CheckButton* refBtnUnique,
                     weld::CheckButton* refBtnCopyResult,
                     weld::CheckButton* refBtnDestPers,
                     weld::ComboBox* refLbCopyArea,
                     formula::WeldRefEdit* refEdCopyArea,
                     formula::WeldRefButton* refRbCopyArea,
                     weld::Label* refFtDbAreaLabel,
                     weld::Label* refFtDbArea,
                     const OUString& refStrUndefined );
    ~FilterOptionsMgr();
    bool    VerifyPosStr ( const OUString& rPosStr ) const;

private:
    ScViewData* const     pViewData;
    ScDocument* const     pDoc;

    weld::CheckButton* pBtnCase;
    weld::CheckButton* pBtnRegExp;
    weld::CheckButton* pBtnHeader;
    weld::CheckButton* pBtnUnique;
    weld::CheckButton* pBtnCopyResult;
    weld::CheckButton* pBtnDestPers;
    weld::ComboBox* pLbCopyArea;
    formula::WeldRefEdit* pEdCopyArea;
    formula::WeldRefButton* pRbCopyArea;
    weld::Label* pFtDbAreaLabel;
    weld::Label* pFtDbArea;

    const OUString&   rStrUndefined;

    const ScQueryParam& rQueryData;

private:
    void Init();

    // Handler:
    DECL_LINK( EdAreaModifyHdl, formula::WeldRefEdit&, void );
    DECL_LINK( LbAreaSelHdl, weld::ComboBox&, void );
    DECL_LINK( BtnCopyResultHdl, weld::ToggleButton&, void );
};


#endif // INCLUDED_SC_SOURCE_UI_INC_FOPTMGR_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
