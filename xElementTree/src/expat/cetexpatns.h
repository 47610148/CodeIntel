/* Copyright (c) 2005-2007 ActiveState Software Inc.
 *
 * Namespace all expat exported symbols to avoid dynamic loading symbol
 * collisions.
 *
 * The Problem:
 * - you embed Python in some app
 * - the app dynamically loads libexpat of version X
 * - the embedded Python imports cElementTree (which was built against
 *   expat version X+n)
 * --> cElementTree gets the expat symbols from the already loaded and *older*
 *     libexpat: crash.
 *
 * The Solution:
 * Prefix all a exported symbols with "CET_". This is similar to
 * what Mozilla does for some common libs:
 * http://lxr.mozilla.org/seamonkey/source/modules/libimg/png/mozpngconf.h#115
 *
 * The list of relevant exported symbols can be had with this command:
 * 
       nm cElementTree.so \
           | grep -v " [a-zBUA] " \
           | grep -v "_fini\|_init\|initcElementTree"
 */

#ifndef CETEXPATNS_H
#define CETEXPATNS_H

#define XML_DefaultCurrent              CET_XML_DefaultCurrent
#define XML_ErrorString                 CET_XML_ErrorString
#define XML_ExpatVersion                CET_XML_ExpatVersion
#define XML_ExpatVersionInfo            CET_XML_ExpatVersionInfo
#define XML_ExternalEntityParserCreate  CET_XML_ExternalEntityParserCreate
#define XML_FreeContentModel            CET_XML_FreeContentModel
#define XML_GetBase                     CET_XML_GetBase
#define XML_GetBuffer                   CET_XML_GetBuffer
#define XML_GetCurrentByteCount         CET_XML_GetCurrentByteCount
#define XML_GetCurrentByteIndex         CET_XML_GetCurrentByteIndex
#define XML_GetCurrentColumnNumber      CET_XML_GetCurrentColumnNumber
#define XML_GetCurrentLineNumber        CET_XML_GetCurrentLineNumber
#define XML_GetErrorCode                CET_XML_GetErrorCode
#define XML_GetFeatureList              CET_XML_GetFeatureList
#define XML_GetIdAttributeIndex         CET_XML_GetIdAttributeIndex
#define XML_GetInputContext             CET_XML_GetInputContext
#define XML_GetParsingStatus            CET_XML_GetParsingStatus
#define XML_GetSpecifiedAttributeCount  CET_XML_GetSpecifiedAttributeCount
#define XmlGetUtf16InternalEncoding     CET_XmlGetUtf16InternalEncoding
#define XmlGetUtf16InternalEncodingNS   CET_XmlGetUtf16InternalEncodingNS
#define XmlGetUtf8InternalEncoding      CET_XmlGetUtf8InternalEncoding
#define XmlGetUtf8InternalEncodingNS    CET_XmlGetUtf8InternalEncodingNS
#define XmlInitEncoding                 CET_XmlInitEncoding
#define XmlInitEncodingNS               CET_XmlInitEncodingNS
#define XmlInitUnknownEncoding          CET_XmlInitUnknownEncoding
#define XmlInitUnknownEncodingNS        CET_XmlInitUnknownEncodingNS
#define XML_MemFree                     CET_XML_MemFree
#define XML_MemMalloc                   CET_XML_MemMalloc
#define XML_MemRealloc                  CET_XML_MemRealloc
#define XML_Parse                       CET_XML_Parse
#define XML_ParseBuffer                 CET_XML_ParseBuffer
#define XML_ParserCreate                CET_XML_ParserCreate
#define XML_ParserCreate_MM             CET_XML_ParserCreate_MM
#define XML_ParserCreateNS              CET_XML_ParserCreateNS
#define XML_ParserFree                  CET_XML_ParserFree
#define XML_ParserReset                 CET_XML_ParserReset
#define XmlParseXmlDecl                 CET_XmlParseXmlDecl
#define XmlParseXmlDeclNS               CET_XmlParseXmlDeclNS
#define XmlPrologStateInit              CET_XmlPrologStateInit
#define XmlPrologStateInitExternalEntity    CET_XmlPrologStateInitExternalEntity
#define XML_ResumeParser                CET_XML_ResumeParser
#define XML_SetAttlistDeclHandler       CET_XML_SetAttlistDeclHandler
#define XML_SetBase                     CET_XML_SetBase
#define XML_SetCdataSectionHandler      CET_XML_SetCdataSectionHandler
#define XML_SetCharacterDataHandler     CET_XML_SetCharacterDataHandler
#define XML_SetCommentHandler           CET_XML_SetCommentHandler
#define XML_SetDefaultHandler           CET_XML_SetDefaultHandler
#define XML_SetDefaultHandlerExpand     CET_XML_SetDefaultHandlerExpand
#define XML_SetDoctypeDeclHandler       CET_XML_SetDoctypeDeclHandler
#define XML_SetElementDeclHandler       CET_XML_SetElementDeclHandler
#define XML_SetElementHandler           CET_XML_SetElementHandler
#define XML_SetEncoding                 CET_XML_SetEncoding
#define XML_SetEndCdataSectionHandler   CET_XML_SetEndCdataSectionHandler
#define XML_SetEndDoctypeDeclHandler    CET_XML_SetEndDoctypeDeclHandler
#define XML_SetEndElementHandler        CET_XML_SetEndElementHandler
#define XML_SetEndNamespaceDeclHandler  CET_XML_SetEndNamespaceDeclHandler
#define XML_SetEntityDeclHandler        CET_XML_SetEntityDeclHandler
#define XML_SetExternalEntityRefHandler CET_XML_SetExternalEntityRefHandler
#define XML_SetExternalEntityRefHandlerArg  CET_XML_SetExternalEntityRefHandlerArg
#define XML_SetNamespaceDeclHandler     CET_XML_SetNamespaceDeclHandler
#define XML_SetNotationDeclHandler      CET_XML_SetNotationDeclHandler
#define XML_SetNotStandaloneHandler     CET_XML_SetNotStandaloneHandler
#define XML_SetParamEntityParsing       CET_XML_SetParamEntityParsing
#define XML_SetProcessingInstructionHandler CET_XML_SetProcessingInstructionHandler
#define XML_SetReturnNSTriplet          CET_XML_SetReturnNSTriplet
#define XML_SetSkippedEntityHandler     CET_XML_SetSkippedEntityHandler
#define XML_SetStartCdataSectionHandler CET_XML_SetStartCdataSectionHandler
#define XML_SetStartDoctypeDeclHandler  CET_XML_SetStartDoctypeDeclHandler
#define XML_SetStartElementHandler      CET_XML_SetStartElementHandler
#define XML_SetStartNamespaceDeclHandler    CET_XML_SetStartNamespaceDeclHandler
#define XML_SetUnknownEncodingHandler   CET_XML_SetUnknownEncodingHandler
#define XML_SetUnparsedEntityDeclHandler    CET_XML_SetUnparsedEntityDeclHandler
#define XML_SetUserData                 CET_XML_SetUserData
#define XML_SetXmlDeclHandler           CET_XML_SetXmlDeclHandler
#define XmlSizeOfUnknownEncoding        CET_XmlSizeOfUnknownEncoding
#define XML_StopParser                  CET_XML_StopParser
#define XML_UseForeignDTD               CET_XML_UseForeignDTD
#define XML_UseParserAsHandlerArg       CET_XML_UseParserAsHandlerArg
#define XmlUtf16Encode                  CET_XmlUtf16Encode
#define XmlUtf8Encode                   CET_XmlUtf8Encode


#endif /* !CETEXPATNS_H */
