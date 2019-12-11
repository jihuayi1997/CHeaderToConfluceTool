///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file nplhtmlsurface.h
///
/// \brief npl html surface interface
///

#ifndef __NPL_HTMLSURFACE_H__
#define __NPL_HTMLSURFACE_H__

#include <npl-defines.h>

typedef uint32_t HHTMLBrowser;
const uint32_t INVALID_HTMLBROWSER = 0;

enum EHTMLKeyModifiers
{
	eHTMLKeyModifierNone = 0,
	eHTMLKeyModifierAltDown = 1,					// Alt key down
	eHTMLKeyModifierCtrlDown = 2,					// Ctrl key down
	eHTMLKeyModifierShiftDown = 4,					// Shift key down
};

enum EHTMLMouseButton
{
	eHTMLMouseButtonLeft = 0,						// mouse left button pressed
	eHTMLMouseButtonRight = 1,						// mouse right button pressed
	eHTMLMouseButtonMiddle = 2,						// mouse middle button pressed
};

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief The browser is ready for use
///
struct cbHTML_BrowserReady_t
{
	enum { iEvtType = enNplHtmlSurface + 1 };

	HHTMLBrowser unBrowserHandle;                   // this browser is now fully created and ready to navigate to pages
};

///
/// \brief the browser has a pending paint
///
struct cbHTML_NeedsPaint_t
{
	enum { iEvtType = enNplHtmlSurface + 2 };

	HHTMLBrowser unBrowserHandle;                   // the browser that needs the paint
	cstr_t       pBGRA;
	uint32_t	 unWide;							// the total width of the pBGRA texture
	uint32_t	 unTall;							// the total height of the pBGRA texture
	uint32_t	 unUpdateX;							// the offset in X for the damage rect for this update
	uint32_t	 unUpdateY;							// the offset in Y for the damage rect for this update
	uint32_t	 unUpdateWide;						// the width of the damage rect for this update
	uint32_t	 unUpdateTall;						// the height of the damage rect for this update
	uint32_t	 unScrollX;							// the page scroll the browser was at when this texture was rendered
	uint32_t	 unScrollY;							// the page scroll the browser was at when this texture was rendered
	float		 flPageScale;						// the page scale factor on this page when rendered
	uint32_t	 unPageSerial;						// incremented on each new page load, you can use this to reject draws while navigating to new pages
};

///
/// \brief The browser wanted to navigate to a new page
///
struct cbHTML_StartRequest_t
{
	enum { iEvtType = enNplHtmlSurface + 3 };

	HHTMLBrowser unBrowserHandle;                   // the browser that needs the paint
	pstr_t pchURL;									// the url they wish to navigate to 
	pstr_t pchTarget;								// the html link target type  (i.e _blank, _self, _parent, _top )
	pstr_t pchPostData;								// any posted data for the request
	bool bIsRedirect;								// true if this was a http/html redirect from the last load request
};

///
/// \brief The browser has been requested to close due to user interaction
///
struct cbHTML_CloseBrowser_t
{
	enum { iEvtType = enNplHtmlSurface + 4 };

	HHTMLBrowser unBrowserHandle;                   // tthe handle of the surface 
};

///
/// \brief the browser is navigating to a new url
///
struct cbHTML_URLChanged_t
{
	enum { iEvtType = enNplHtmlSurface + 5 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface navigating
	pstr_t pchURL;									// the url they wish to navigate to 
	pstr_t pchPostData;								// any posted data for the request 
	pstr_t pchPageTitle;							// the title of the page
	bool bNewNavigation;							// true if this was from a fresh tab and not a click on an existing page
	bool bIsRedirect;								// true if this was a http/html redirect from the last load request
};


///
/// \brief A page is finished loading
///
struct cbHTML_FinishedRequest_t
{
	enum { iEvtType = enNplHtmlSurface + 6 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchURL;									// the url which the browser vist
	pstr_t pchPageTitle;							// page title
};


///
/// \brief a request to load this url in a new tab
///
struct cbHTML_OpenLinkInNewTab_t
{
	enum { iEvtType = enNplHtmlSurface + 7 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchURL;									// url
};


///
/// \brief the page has a new title now
///
struct cbHTML_ChangedTitle_t
{
	enum { iEvtType = enNplHtmlSurface + 8 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchTitle;								// new page title
};


///
/// \brief results from a search
///
struct cbHTML_SearchResults_t
{
	enum { iEvtType = enNplHtmlSurface + 9 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	uint32_t unResults;								// the count of results
	uint32_t unCurrentMatch;						// current match index
};

///
/// \brief page history status changed on the ability to go backwards and forward
///
struct cbHTML_CanGoBackAndForward_t
{
	enum { iEvtType = enNplHtmlSurface + 10 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	bool bCanGoBack;								// can be go back?
	bool bCanGoForward;								// can be go forward?
};

///
/// \brief details on the visibility and size of the horizontal scrollbar
///
struct cbHTML_HorizontalScroll_t
{
	enum { iEvtType = enNplHtmlSurface + 11 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	uint32_t unScrollMax;							// The maximum amount you can scroll horizontally.
	uint32_t unScrollCurrent;						// The current horizontal scroll position.
	float flPageScale;								// The current page scale.
	bool bVisible;									// Whether the horizontal scrollbar is visible.
	uint32_t unPageSize;							// The total width of the page in pixels.
};

///
/// \brief details on the visibility and size of the vertical scrollbar
///
struct cbHTML_VerticalScroll_t
{
	enum { iEvtType = enNplHtmlSurface + 12 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	uint32_t unScrollMax;							// The maximum amount you can scroll vertically.
	uint32_t unScrollCurrent;						// The current horizontal scroll position.
	float flPageScale;								// The current page scale.
	bool bVisible;									// Whether the horizontal scrollbar is visible.
	uint32_t unPageSize;							// The total width of the page in pixels.
};


///
/// \brief response to GetLinkAtPosition call 
///
struct cbHTML_LinkAtPosition_t
{
	enum { iEvtType = enNplHtmlSurface + 13 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchURL;									// The URL found at this position. 
};

///
/// \brief show a Javascript alert dialog, call JSDialogResponse when the user dismisses this dialog (or right away to ignore it)
///
struct cbHTML_JSAlert_t
{
	enum { iEvtType = enNplHtmlSurface + 14 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchMessage;								// The message associated with the dialog.
};


///
/// \brief show a Javascript confirmation dialog, call JSDialogResponse when the user dismisses this dialog (or right away to ignore it)
///
struct cbHTML_JSConfirm_t
{
	enum { iEvtType = enNplHtmlSurface + 15 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchMessage;								// The message associated with the dialog.
};


///
/// \brief when received show a file open dialog then call FileLoadDialogResponse with the file(s) the user selected.
///
struct cbHTML_FileOpenDialog_t
{
	enum { iEvtType = enNplHtmlSurface + 16 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchTitle;								// The name of the dialog
	pstr_t pchInitialFile;							// The filename that the page wants you to set by default. It may be expecting a file with that name or that was the file the user previously uploaded
};


///
/// \brief a new html window has been created 
///
struct cbHTML_NewWindow_t
{
	enum { iEvtType = enNplHtmlSurface + 21 };
	HHTMLBrowser unBrowserHandle;					// the handle of the current surface 
	pstr_t pchURL;									// the page to load
	uint32_t unX;									// the x pos into the page to display the popup
	uint32_t unY;									// the y pos into the page to display the popup
	uint32_t unWide;								// the total width of the pBGRA texture
	uint32_t unTall;								// the total height of the pBGRA texture
	HHTMLBrowser unNewWindow_BrowserHandle;			// the handle of the new window surface 
};


///
/// \brief change the cursor to display
///
struct cbHTML_SetCursor_t
{
	enum { iEvtType = enNplHtmlSurface + 22 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	uint32_t eMouseCursor;							// the EMouseCursor to display  /see cef_cursor_type_t
};

///
/// \brief informational message from the browser
///
struct cbHTML_StatusText_t
{
	enum { iEvtType = enNplHtmlSurface + 23 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchMsg;									// The text of the status message to display.
};

///
/// \brief show a tooltip
///
struct cbHTML_ShowToolTip_t
{
	enum { iEvtType = enNplHtmlSurface + 24 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchMsg;									// The text of the tooltip that wants to be displayed.
};

///
/// \brief update the text of an existing tooltip
///
struct cbHTML_UpdateToolTip_t
{
	enum { iEvtType = enNplHtmlSurface + 25 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
	pstr_t pchMsg;									// The text of the tooltip that wants to be displayed.
};


///
/// \brief hide the tooltip you are showing
///
struct cbHTML_HideToolTip_t
{
	enum { iEvtType = enNplHtmlSurface + 26 };
	HHTMLBrowser unBrowserHandle;					// the handle of the surface 
};


#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
///
/// \brief 实时语音模块接口
///
struct NPL_API INplHtmlSurface
{
	///
	/// \brief Must call init when starting use of the interface
	///
	virtual bool Init() = 0;

	///
	/// \brief Must call shutdown when ending use of the interface
	///
	virtual bool Shutdown() = 0;

	///
	/// \brief Create a browser object for display of a html page.
	///
	/// \param pchUserAgent The user agent string is a substring to be added to the general 
	///                     user agent string so you can identify your client on web servers.
	/// \param pchUserCSS a CSS style sheet to every displayed page, 
	///					  leave null if you do not require this functionality.
	/// \see RegistEvent cbHTML_BrowserReady_t
	///
	virtual void CreateBrowser(const char *pchUserAgent, const char *pchUserCSS) = 0;

	///
	/// \brief Call this when you are done with a html surface, this lets us free the resources being used by it
	///
	/// \param unBrowserHandle  Browser's handle
	///
	virtual void RemoveBrowser(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief Navigate to this URL
	///
	/// \param unBrowserHandle Browser's handle
	/// \param pchURL The URL to load.
	/// \param pchPostData Optionally send a POST request with this data, set this to NULL to not send any data.
	///
	/// \see RegistEvent HTML_StartRequest_t
	///
	virtual void LoadURL(HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData) = 0;

	///
	/// \brief Tells the surface the size in pixels to display the surface
	///
	/// \param unBrowserHandle Browser's handle
	/// \param unWidth The width of the surface in pixels.
	/// \param unHeight The height of the surface in pixels.
	///
	virtual void SetSize(HHTMLBrowser unBrowserHandle, uint32_t unWidth, uint32_t unHeight) = 0;

	///
	/// \brief Stop the load of the current html page
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void StopLoad(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief Reload (most likely from local cache) the current page
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void Reload(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief navigate back in the page history
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void GoBack(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief navigate forward in the page history
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void GoForward(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief add this header to any url requests from this browser
	///
	/// \param unBrowserHandle Browser's handle
	/// \param pchKey The header name to add
	/// \param pchValue The header value to associate with the key
	///
	virtual void AddHeader(HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue) = 0;

	///
	/// \brief run this javascript script in the currently loaded page
	///
	/// \param unBrowserHandle Browser's handle
	/// \param pchScript The javascript script to run
	///
	virtual void ExecuteJavascript(HHTMLBrowser unBrowserHandle, const char *pchScript) = 0;

	///
	/// \brief Mouse click commands
	///
	/// \param unBrowserHandle Browser's handle
	/// \param eMouseButton The mouse button which was released
	///
	virtual void MouseUp(HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton) = 0;
	virtual void MouseDown(HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton) = 0;
	virtual void MouseDoubleClick(HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton) = 0;
	
	///
	/// \brief Mouse movement commands
	///
	/// \param unBrowserHandle Browser's handle
	/// \param x Mouse position of x
	/// \param y Mouse position of Y
	///
	virtual void MouseMove(HHTMLBrowser unBrowserHandle, int x, int y) = 0;
	
	///
	/// \brief Mouse wheel commands
	///
	/// \param unBrowserHandle Browser's handle
	/// \param nDelta The number of pixels to scroll
	///
	virtual void MouseWheel(HHTMLBrowser unBrowserHandle, sint32_t nDelta) = 0;

	///
	/// \brief Keybroad commands
	///
	/// \param unBrowserHandle Browser's handle
	/// \param nNativeKeyCode This is the virtual keycode value from the OS
	/// \param eHTMLKeyModifiers This should be set to a bitmask of the modifier keys that the user is currently pressing
	///
	virtual void KeyDown(HHTMLBrowser unBrowserHandle, uint32_t nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) = 0;
	virtual void KeyUp(HHTMLBrowser unBrowserHandle, uint32_t nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) = 0;
	virtual void KeyChar(HHTMLBrowser unBrowserHandle, uint32_t cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers) = 0;

	///
	/// \brief programmatically scroll this many pixels on the page
	///
	/// \param unBrowserHandle Browser's handle
	/// \param nAbsolutePixelScroll The absolute pixel position to scroll to
	///
	virtual void SetHorizontalScroll(HHTMLBrowser unBrowserHandle, uint32_t nAbsolutePixelScroll) = 0;
	virtual void SetVerticalScroll(HHTMLBrowser unBrowserHandle, uint32_t nAbsolutePixelScroll) = 0;

	///
	/// \brief tell the html control if it has key focus currently, controls showing the I-beam cursor in text controls amongst other things
	///
	/// \param unBrowserHandle Browser's handle
	/// \param bHasKeyFocus Turn key focus on or off
	///
	virtual void SetKeyFocus(HHTMLBrowser unBrowserHandle, bool bHasKeyFocus) = 0;

	///
	/// \brief open the current pages html code in the local editor of choice, used for debugging
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void ViewSource(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief copy the currently selected text on the html page to the local clipboard
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void CopyToClipboard(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief paste from the local clipboard to the current html page
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void PasteFromClipboard(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief find this string in the browser, if bCurrentlyInFind is true then instead cycle to the next matching element
	///
	/// \param unBrowserHandle Browser's handle
	/// \param pchSearchStr The string to search for
	/// \param bCurrentlyInFind  Set this to true on subsequent calls to cycle through to the next matching string
	/// \param bReverse  Search from the bottom up
	///
	virtual void Find(HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse) = 0;

	///
	/// \brief cancel a currently running find
	///
	/// \param unBrowserHandle Browser's handle
	///
	virtual void StopFind(HHTMLBrowser unBrowserHandle) = 0;

	///
	/// \brief return details about the link at position x,y on the current page
	///
	/// \param unBrowserHandle Browser's handle
	/// \param x  The X (width) position in pixels within the surface. (0, 0) is the top left corner
	/// \param y  The Y (height) position in pixels within the surface. (0, 0) is the top left corner
	///
	virtual void GetLinkAtPosition(HHTMLBrowser unBrowserHandle, int x, int y) = 0;

	///
	/// \brief set a webcookie for the hostname in question
	///
	/// \param pchHostname The hostname of the server to set the cookie for. ('Host' attribute)
	/// \param pchKey The cookie name to set.
	/// \param pchValue The cookie value to set.
	/// \param pchPath Sets the 'Path' attribute on the cookie. You can use this to restrict the cookie to a specific path on the domain. e.g. "/accounts"
	/// \param nExpires Sets the 'Expires' attribute on the cookie to the specified timestamp in Unix epoch format
	/// \param bSecure Sets the 'Secure' attribute.
	/// \param bHTTPOnly Sets the 'HttpOnly' attribute.
	///
	virtual void SetCookie(const char *pchHostname, const char *pchKey, const char *pchValue, 
		const char *pchPath = "/", float nExpires = 0, bool bSecure = false, bool bHTTPOnly = false) = 0;

	///
	/// \brief Zoom the current page by flZoom ( from 0.0 to 2.0, so to zoom to 120% use 1.2 ), 
	///        zooming around point X,Y in the page (use 0,0 if you don't care)
	///
	/// \param unBrowserHandle Browser's handle
	/// \param flZoom The amount to zoom, this can range from 1 (100% and the default) to 2 (200%).
	/// \param nPointX The X point in pixels to zoom around. Use 0 if you don't care.
	/// \param nPointY The Y point in pixels to zoom around. Use 0 if you don't care.
	///
	virtual void SetPageScaleFactor(HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY) = 0;

	///
	/// \brief Enable/disable low-resource background mode, where javascript and repaint timers are throttled, resources are
	///        more aggressively purged from memory, and audio/video elements are paused. When background mode is enabled,
	///	       all HTML5 video and audio objects will execute ".pause()" and gain the property "._steam_background_paused = 1".
	///	       When background mode is disabled, any video or audio objects with that property will resume with ".play()".
	///
	/// \param unBrowserHandle Browser's handle
	/// \param bBackgroundMode does use background mode
	///
	virtual void SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode) = 0;
	
	///
	///  \brief  You MUST call this in response to a HTML_StartRequest_t callback
	///	         Set bAllowed to true to allow this navigation, false to cancel it and stay 
	///	         on the current page. You can use this feature to limit the valid pages
	///	         allowed in your HTML surface.
	///
	/// \param unBrowserHandle Browser's handle
	/// \param bAllowed Allow or deny the navigation to the current start request
	///
	virtual void AllowStartRequest(HHTMLBrowser unBrowserHandle, bool bAllowed) = 0;

	///
	/// \brief You MUST call this in response to a HTML_JSAlert_t or HTML_JSConfirm_t callback
	///        Set bResult to true for the OK option of a confirm, use false otherwise
	///
	/// \param unBrowserHandle Browser's handle
	/// \param bResult Set this to true to simulate pressing the "OK" button, otherwise false for "Cancel"
	///
	virtual void JSDialogResponse(HHTMLBrowser unBrowserHandle, bool bResult) = 0;

	///
	/// \brief You MUST call this in response to a HTML_FileOpenDialog_t callback
	///
	/// \param unBrowserHandle Browser's handle
	/// \param pchSelectedFiles The filename that the page wants you to set by default.It may be expecting a file with that name or that was the file the user previously uploaded
	///
	virtual void FileLoadDialogResponse(HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles) = 0;

	///
	/// \brief Show or hiden browser window
	///
	/// \param bShow If bShow is TRUE, the window is being shown. If bShow is FALSE, the window is being hidden.
	///
	virtual void ShowWindow(HHTMLBrowser unBrowserHandle, bool bShow) = 0;
};
}

#endif // __NPL_C_INTERFACE__
#endif // __NPL_HTMLSURFACE_H__
