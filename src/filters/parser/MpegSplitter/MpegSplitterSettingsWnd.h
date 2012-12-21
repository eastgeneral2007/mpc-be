/*
 * $Id$
 *
 * (C) 2006-2012 see Authors.txt
 *
 * This file is part of MPC-BE.
 *
 * MPC-BE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-BE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "../../core/InternalPropertyPage.h"
#include "IMpegSplitterFilter.h"
#include "resource.h"
#include <afxcmn.h>

class __declspec(uuid("44FCB62D-3AEB-401C-A7E1-8A984C017923"))
	CMpegSplitterSettingsWnd : public CInternalPropertyPageWnd
{
private :
	CComQIPtr<IMpegSplitterFilter> m_pMSF;

	CButton		m_cbFastStreamChange;
	CButton		m_cbForcedSub;
	CButton		m_cbTrackPriority;
	CButton		m_cbAlternativeDuration;
	CStatic		m_txtAudioLanguageOrder;
	CEdit		m_edtAudioLanguageOrder;
	CStatic		m_txtSubtitlesLanguageOrder;
	CEdit		m_edtSubtitlesLanguageOrder;

	CButton		m_grpTrueHD;
	CButton		m_cbTrueHD;
	CButton		m_cbAC3Core;
	CButton		m_cbAsIs;

	CButton		m_cbFastSeek;

	enum {
		IDC_PP_FAST_STREAM_SELECT = 10000,
		IDC_PP_SUBTITLE_FORCED,
		IDC_PP_TRACK_PRIORITY,
		IDC_PP_AUDIO_LANGUAGE_ORDER,
		IDC_PP_SUBTITLES_LANGUAGE_ORDER,
		IDC_PP_TRUEHD,
		IDC_PP_AC3CORE,
		IDC_PP_ASIS,
		IDC_PP_ALTERNATIVE_DURATION,
		IDC_PP_FAST_SEEK
	};

public:
	CMpegSplitterSettingsWnd(void);

	bool OnConnect(const CInterfaceList<IUnknown, &IID_IUnknown>& pUnks);
	void OnDisconnect();
	bool OnActivate();
	void OnDeactivate();
	bool OnApply();

	static LPCTSTR GetWindowTitle() {
#ifdef REGISTER_FILTER
		return _T("Settings");
#else
		return MAKEINTRESOURCE(IDS_AG_SETTINGS);
#endif
	}
	static CSize GetWindowSize() { return CSize(325, 230); }

	DECLARE_MESSAGE_MAP()

	afx_msg void OnClickedFastSeek();
};
